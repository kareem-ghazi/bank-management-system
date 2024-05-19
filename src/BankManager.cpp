#include "BankManager.h"

BankManager::BankManager()
{

}

// Checks whether the username and password are correct and returns the authorization status.
bool BankManager::login(string username, string password)
{
	vector<Account> accounts = database.getAccounts();

	for (int i = 0; i < accounts.size(); i++)
	{
		if (username == accounts[i].getOwner().getUsername()
			&& password == accounts[i].getOwner().getPassword())
		{
			return true;
		}
	}

	return false;
}

// Adds an account to the database.
void BankManager::addAccount(Account account)
{
	database.addEntry(account);
}

// Removes an account from the database.
void BankManager::removeAccount(Account account)
{
	database.deleteEntry(account);
}

// Adds a person to the database.
void BankManager::addPerson(Person person)
{
	database.addEntry(person);
}

// Returns the person according to their username.
Person BankManager::getPerson(string username) const
{
	vector<Person> people = database.getPeople();

	for (int i = 0; i < people.size(); i++)
	{
		if (username == people[i].getUsername())
		{
			return people[i];
		}
	}

	return Person();
}

// Gets a copy of an account from the database using the account number.
Account BankManager::getAccount(long long accountNumber)
{
	vector<Account> accounts = database.getAccounts();

	for (int i = 0; i < accounts.size(); i++)
	{
		if (accountNumber == accounts[i].getAccountNumber())
		{
			return accounts[i];
		}
	}

	return Account();
}

// Gets a list of copied accounts from the database according to the given Person object.
vector<Account> BankManager::getAccountsOf(Person person) const
{
	vector<Account> accounts = database.getAccounts();
	vector<Account> accountsOf;

	for (int i = 0; i < accounts.size(); i++)
	{
		if (person.getUsername() == accounts[i].getOwner().getUsername())
		{
			accountsOf.push_back(accounts[i]);
		}
	}

	return accountsOf;
}

int BankManager::getNumberOfAccounts(Person person) const
{
	vector<Account> accounts = database.getAccounts();

	int count = 0;

	for (int i = 0; i < accounts.size(); i++)
	{
		if (person.getUsername() == accounts[i].getOwner().getUsername())
		{
			count++;
		}
	}

	return count;
}

void BankManager::printInformation(Account account)
{
	Account* originalAccount = database.getAccount(account.getAccountNumber());

	cout << endl;

	cout << "==========================" << endl;
	cout << "Account Owner: " << originalAccount->getOwner().getName()
		<< " (" << originalAccount->getOwner().getUsername() << ")" << endl;
	cout << "Account Number: " << originalAccount->getAccountNumber() << endl;
	cout << "Account Balance: " << fixed << setprecision(2) << originalAccount->getBalance() << endl;
	cout << "==========================" << endl;

	cout << endl;
}

void BankManager::printInformation(Person person)
{
	cout << endl;

	cout << "==========================" << endl;
	cout << "Name: " << person.getName() << endl;
	cout << "Username: " << person.getUsername() << endl;
	cout << "Age: " << person.getAge() << endl;
	cout << "Address: " << person.getAddress() << endl;
	cout << "Owned Accounts: " << getNumberOfAccounts(person) << endl;
	cout << "==========================" << endl;

	cout << endl;
}

bool BankManager::findUsername(string username)
{
	vector<Person> people = database.getPeople();

	for (int i = 0; i < people.size(); i++)
	{
		if (username == people[i].getUsername())
		{
			return true;
		}
	}

	return false;
}

void BankManager::deposit(Account account, double amount)
{
	Account* originalAccount = database.getAccount(account.getAccountNumber());

	Deposit deposit(*originalAccount);
	deposit.setAmount(amount);

	originalAccount->deposit(amount);
	invoice.addTransaction(deposit);
}

void BankManager::withdraw(Account account, double amount)
{
	Account* originalAccount = database.getAccount(account.getAccountNumber());

	Withdraw withdraw(*originalAccount);
	withdraw.setAmount(amount);

	originalAccount->withdraw(amount);
	invoice.addTransaction(withdraw);
}

void BankManager::transfer(Account accountFrom, Account accountTo, double amount)
{
	Account* originalAccountFrom = database.getAccount(accountFrom.getAccountNumber());
	Account* originalAccountTo = database.getAccount(accountTo.getAccountNumber());

	Transfer transfer(accountFrom, accountTo);
	transfer.setAmount(amount);

	originalAccountFrom->transfer(originalAccountTo, amount);
	invoice.addTransaction(transfer);
}

void BankManager::clearInvoice()
{
	invoice.clearTransactions();
}

void BankManager::printInvoice(Account account)
{
	vector<Deposit> deposits = invoice.getDeposits();
	vector<Withdraw> withdraws = invoice.getWithdraws();
	vector<Transfer> transfers = invoice.getTransfers();

	int count = 1;

	cout << endl << "===========================" << endl;

	for (int i = 0; i < deposits.size(); i++, count++)
	{
		cout << "Transaction #" << count << ": " << "(DEPOSIT)" << endl;
		cout << "Amount: " << deposits[i].getAmount() << endl << endl;
	}

	for (int i = 0; i < withdraws.size(); i++, count++)
	{
		cout << "Transaction #" << count << ": " << "(WITHDRAW)" << endl;
		cout << "Amount: " << withdraws[i].getAmount() << endl << endl;
	}

	for (int i = 0; i < transfers.size(); i++, count++)
	{
		cout << "Transaction #" << count << ": " << "(TRANSFER)" << endl;
		cout << transfers[i].getAccountFrom().getOwner().getUsername() << " >>>> "
			<< transfers[i].getAccountTo().getOwner().getUsername() << endl;
		cout << "Amount: " << transfers[i].getAmount() << endl;
	}

	cout << "===========================" << endl << endl;
}

void BankManager::printForeignRates(int inputCurrency, double amount)
{
	cout << endl;

	switch (inputCurrency)
	{
	case 1:
		cout << "=====================================" << endl;
		cout << "Your entered amount is: $" << amount << " USD" << endl;
		cout << "=====================================" << endl;
		cout << "EGP: " << amount * 46.91 << " L.E." << endl;
		cout << "EURO: " << amount * 0.92 << " EUR" << endl;
		cout << "RIYAL: " << amount * 3.75 << " SAR" << endl;
		cout << "POUND: " << amount * 0.79 << " GBP" << endl;
		cout << "YUAN: " << amount * 7.22 << " CNY" << endl;
		cout << "=====================================" << endl;
		break;
	case 2:
		cout << "=====================================" << endl;
		cout << "Your entered amount is: $" << amount << " L.E." << endl;
		cout << "=====================================" << endl;
		cout << "DOLLAR: " << amount * 0.021 << " USD" << endl;
		cout << "EURO: " << amount * 0.020 << " EUR" << endl;
		cout << "RIYAL: " << amount * 0.08 << " SAR" << endl;
		cout << "POUND: " << amount * 0.017 << " GBP" << endl;
		cout << "YUAN: " << amount * 0.15 << " CNY" << endl;
		cout << "=====================================" << endl;
		break;
	case 3:
		cout << "=====================================" << endl;
		cout << "Your entered amount is: $" << amount << " EUR" << endl;
		cout << "=====================================" << endl;
		cout << "EGP: " << amount * 50.91 << " L.E." << endl;
		cout << "DOLLAR: " << amount * 1.09 << " USD" << endl;
		cout << "RIYAL: " << amount * 4.08 << " SAR" << endl;
		cout << "POUND: " << amount * 0.86 << " GBP" << endl;
		cout << "YUAN: " << amount * 7.86 << " CNY" << endl;
		cout << "=====================================" << endl;
		break;
	case 4:
		cout << "=====================================" << endl;
		cout << "Your entered amount is: $" << amount << " SAR" << endl;
		cout << "=====================================" << endl;
		cout << "EGP: " << amount * 12.48 << " L.E." << endl;
		cout << "EURO: " << amount * 0.24 << " EUR" << endl;
		cout << "DOLLAR: " << amount * 0.27 << " USD" << endl;
		cout << "POUND: " << amount * 0.21 << " GBP" << endl;
		cout << "YUAN: " << amount * 1.93 << " CNY" << endl;
		cout << "=====================================" << endl;
		break;
	case 5:
		cout << "=====================================" << endl;
		cout << "Your entered amount is: $" << amount << " GBP" << endl;
		cout << "=====================================" << endl;
		cout << "EGP: " << amount * 59.29 << " L.E." << endl;
		cout << "EURO: " << amount * 1.16 << " EUR" << endl;
		cout << "RIYAL: " << amount * 4.75 << " SAR" << endl;
		cout << "DOLLAR: " << amount * 1.27 << " USD" << endl;
		cout << "YUAN: " << amount * 9.15 << " CNY" << endl;
		cout << "=====================================" << endl;
		break;
	case 6:
		cout << "=====================================" << endl;
		cout << "Your entered amount is: $" << amount << " CNY" << endl;
		cout << "=====================================" << endl;
		cout << "EGP: " << amount * 6.6 << " L.E." << endl;
		cout << "EURO: " << amount * 0.13 << " EUR" << endl;
		cout << "RIYAL: " << amount * 0.53 << " SAR" << endl;
		cout << "POUND: " << amount * 0.11 << " GBP" << endl;
		cout << "DOLLAR: " << amount * 0.14 << " USD" << endl;
		cout << "=====================================" << endl;
		break;
	default:
		cout << "Error: Invalid currency." << endl;
		break;
	}

	cout << endl;
}



