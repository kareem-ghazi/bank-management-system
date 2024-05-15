#include "BankManager.h"

BankManager::BankManager()
{
	Dollar = 0.021;
	Riyal = 0.0787;
	Euro = 0.0196;
	Dinar = 0.0065;
	Pound = 0.0167;
}

void BankManager::setvalue()
{
	int temp = 0;
	do
	{

		cout << "Enter the number in Egyptian pounds :" << endl;

		cin >> num;
		if (num <= 0)
		{
			cout << "invaled number\n";
			temp++;
		}
		else
		{
			cout << "Enter the currency :" << endl;
			cout << "[1] Dollar - [2] Euro - [3] Riyal - [4] Kuwaiti dinar - [5] Pound\n";
			cin >> currency;
			temp = 0;

		}


	} while (temp);

}

double BankManager::result()
{
	if (currency == 1)
	{
		return Dollar * num;
	}
	else if (currency == 2)
	{
		return Euro * num;
	}
	else if (currency == 3)
	{
		return Riyal * num;
	}
	else if (currency == 4)
	{
		return Dinar * num;
	}
	else if (currency == 5)
	{
		return Pound * num;
	}
	else
	{
		cout << "Invalid currency" << endl;
		return 0;
	}
}

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

void BankManager::addAccount(Account account)
{
	database.addEntry(account);
}

void BankManager::removeAccount(Account account)
{
	database.deleteEntry(account);
}

void BankManager::addPerson(Person person)
{
	database.addEntry(person);
}

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

	cout << "==========================" << endl;
	cout << "Account Owner: " << originalAccount->getOwner().getName()
		<< "(" << originalAccount->getOwner().getUsername() << ")" << endl;
	cout << "Account Number: " << originalAccount->getAccountNumber() << endl;
	cout << "Account Balance: " << originalAccount->getBalance() << endl;
	cout << "==========================" << endl;
}

void BankManager::printInformation(Person person)
{
	cout << "==========================" << endl;
	cout << "Name: " << person.getName() << endl;
	cout << "Username: " << person.getUsername() << endl;
	cout << "Age: " << person.getAge() << endl;
	cout << "Address: " << person.getAddress() << endl;
	cout << "Owned Accounts: " << getNumberOfAccounts(person) << endl;
	cout << "==========================" << endl;
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

	cout << "===========================" << endl;

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

	cout << "===========================" << endl;
}



