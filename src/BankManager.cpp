#include "BankManager.h"

// Empty constructor.
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

// Returns the number of accounts a single person has.
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

// Prints the information of an account in the database.
void BankManager::printInformation(Account account)
{
	Account* originalAccount = database.getAccount(account.getAccountNumber());

	cout << endl;

	cout << "=====================================" << endl;
	cout << "Account Owner: " << originalAccount->getOwner().getName()
		<< " (" << originalAccount->getOwner().getUsername() << ")" << endl;
	cout << "Account Number: " << originalAccount->getAccountNumber() << endl;
	cout << "Account Balance: " << fixed << setprecision(2) << originalAccount->getBalance() << endl;
	cout << "=====================================" << endl;

	cout << endl;
}

// Prints the information of a person.
void BankManager::printInformation(Person person)
{
	cout << endl;

	cout << "=====================================" << endl;
	cout << "Name: " << person.getName() << endl;
	cout << "Username: " << person.getUsername() << endl;
	cout << "Age: " << person.getAge() << endl;
	cout << "Address: " << person.getAddress() << endl;
	cout << "Owned Accounts: " << getNumberOfAccounts(person) << endl;
	cout << "=====================================" << endl;

	cout << endl;
}

// Checks whether a username exists in the database or not.
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

// Deposits an amount of money to an account in the database.
void BankManager::deposit(Account account, double amount)
{
	Account* originalAccount = database.getAccount(account.getAccountNumber());

	Deposit deposit(*originalAccount);
	deposit.setAmount(amount);
	deposit.setDate(getDate());

	bool status = originalAccount->deposit(amount);
	if (status)
	{
		invoice.addTransaction(deposit);
	}
}

// Withdraws an amount of money from an account in the database.
void BankManager::withdraw(Account account, double amount)
{
	Account* originalAccount = database.getAccount(account.getAccountNumber());

	Withdraw withdraw(*originalAccount);
	withdraw.setAmount(amount);
	withdraw.setDate(getDate());

	bool status = originalAccount->withdraw(amount);
	if (status)
	{
		invoice.addTransaction(withdraw);
	}
}

// Transfers an amount of money from an account to another account in the database.
void BankManager::transfer(Account accountFrom, Account accountTo, double amount)
{
	Account* originalAccountFrom = database.getAccount(accountFrom.getAccountNumber());
	Account* originalAccountTo = database.getAccount(accountTo.getAccountNumber());

	Transfer transfer(accountFrom, accountTo);
	transfer.setAmount(amount);
	transfer.setDate(getDate());

	bool status = originalAccountFrom->transfer(originalAccountTo, amount);
	if (status)
	{
		invoice.addTransaction(transfer);
	}
}

// Clears the invoice.
void BankManager::clearInvoice()
{
	invoice.clearTransactions();
}

// Prints the invoice if it is not empty with all the transactions made.
void BankManager::printInvoice(Account account)
{
	vector<Deposit> deposits = invoice.getDeposits();
	vector<Withdraw> withdraws = invoice.getWithdraws();
	vector<Transfer> transfers = invoice.getTransfers();

	if (deposits.size() == 0 && withdraws.size() == 0 && transfers.size() == 0)
	{
		cout << "[!] Error: No invoice exists for this current login session." << endl;
		return;
	}

	int count = 1;

	cout << "=====================================" << endl;

	for (int i = 0; i < deposits.size(); i++, count++)
	{
		cout << "Transaction #" << count << ": " << "(DEPOSIT)" << endl;
		cout << "Date: " << deposits[i].getDate() << endl;
		cout << "Amount: " << deposits[i].getAmount() << endl << endl;
	}

	for (int i = 0; i < withdraws.size(); i++, count++)
	{
		cout << "Transaction #" << count << ": " << "(WITHDRAW)" << endl;
		cout << "Date: " << withdraws[i].getDate() << endl;
		cout << "Amount: " << withdraws[i].getAmount() << endl << endl;
	}

	for (int i = 0; i < transfers.size(); i++, count++)
	{
		cout << "Transaction #" << count << ": " << "(TRANSFER)" << endl;
		cout << transfers[i].getAccountFrom().getOwner().getUsername() << " >>>> "
			<< transfers[i].getAccountTo().getOwner().getUsername() << endl;
		cout << "Date: " << transfers[i].getDate() << endl;
		cout << "Amount: " << transfers[i].getAmount() << endl;
	}

	cout << "=====================================" << endl;
}

// Checks the foreign currency rates for a given currency and an amount of it.
void BankManager::printForeignRates(int inputCurrency, double amount)
{
	cout << endl;

	switch (inputCurrency)
	{
	case 1:
		cout << "=====================================" << endl;
		cout << "Your entered amount is: " << amount << " USD" << endl;
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
		cout << "Your entered amount is: " << amount << " L.E." << endl;
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
		cout << "Your entered amount is: " << amount << " EUR" << endl;
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
		cout << "Your entered amount is: " << amount << " SAR" << endl;
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
		cout << "Your entered amount is: " << amount << " GBP" << endl;
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
		cout << "Your entered amount is: " << amount << " CNY" << endl;
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

// Returns the current date using the ctime function from the <ctime> library.
string BankManager::getDate()
{
	// Store the current time into time_t (an arithmetic type used for storage of time).
	// Reference: https://en.cppreference.com/w/c/chrono/time_t
	time_t now = time(0);

	char dateChar[50];
	// Simply converts the original time_t variable into a character array along with its size.
	// Reference: https://en.cppreference.com/w/c/chrono/ctime
	ctime_s(dateChar, 50, &now);

	// Converting the character array into a string.
	// NOTE: It seems like the ctime function adds a '\n' character at the end of the character array.
	// The current workaround is to remove it from the end of the string.
	string date(dateChar);
	date[date.size() - 1] = ' ';

	return date;
}



