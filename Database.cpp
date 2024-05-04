#include "Database.h"

bool Database::is16Digts(long long num1)
{
	long long div = num1 / 1000000000000000;
	if (div < 0 || div == 0 || div >= 10)
	{
		return false;
	}
	return true;
}

void Database::addAccount()
{
	dataMgt.open("./data/accounts.txt", ios::app);
	dataMgtc.open("./data/cardnumber.txt", ios::app);

	int temp = 1;
	long long waiting = 0;
	string swaiting;
	while (temp)
	{
		cout << "enter the number of the account\n";
		cin >> waiting;
		cout << "what is the name of the cardholder ?\n";
		cin >> swaiting;
		if (!(is16Digts(waiting)))
		{
			cout << "invaled number\n";
			continue;
		}

		dataMgt << swaiting << "\n";
		dataMgtc << waiting << "\n";

		cout << "do you want any thing else sir?\n";
		cout << "[1]\tyes\n";
		cout << "[0]\tno\n";
		cin >> temp;
	}

	dataMgt.close();
	dataMgtc.close();
}

void Database::readAccount()
{
	dataMgt.open("./data/accounts.txt", ios::in);
	dataMgtc.open("./data/cardnumber.txt", ios::in);
	int chosen = 0;
	for (int i = 0; i < 20; i++)
	{
		getline(dataMgt, reader[i]);
		getline(dataMgtc, readerc[i]);
		//balance
		//log
	}
	for (int i = 0; i < 20; i++)
	{
		cout << i + 1 << " : " << reader[i] << "\n";
	}

	cout << "choose\n";
	cin >> chosen;
	cout << "=============================================\n";
	cout << "\t\t Name :\t" << reader[chosen - 1] << "\n";
	cout << "\t\t Cardnumber :\t" << readerc[chosen - 1] << "\n";

	dataMgt.close();
	dataMgtc.close();
}