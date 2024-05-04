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
	cout << "Enter the number in Egyptian pounds :" << endl;
	cin >> num;
	cout << "Enter the currency :" << endl;
	cout << "Dollar=1 - Euro=2 - Riyal=3 - Kuwaiti Dinar=4 - Pound=5" << endl;
	cin >> currency;
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