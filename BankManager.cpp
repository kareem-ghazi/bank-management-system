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