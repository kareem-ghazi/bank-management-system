#include "Transfer.h"

//void Transfer::main_menu()
//{
//    int choose = 0;
//    /*double temp = 0;*/
//    //cout << "wright you card number\n";
//    //cout << "wright the card number you want to transfer to\n";
//
//    cout << "=======\t\t Trasfer menu \t\t=======\n\n";
//    cout << "     [1] 100 \t [2] 300 \t [3] 500\t\n\n";
//    cout << "     [4] 1000 \t [5] 2000 \t [6] other\n";
//    cin >> choose;
//
//    switch (choose)
//    {
//    case 1:
//    {
//
//        if (amount < 100.00)
//        {
//            cout << "failed transaction\n";
//        }
//        else
//        {
//            amount -= 100.00;
//            balance_B += 100.00;
//            cout << "sucsesful transaction\n";
//        }
//
//    }
//    break;
//
//    case 2:
//    {
//
//        if (amount < 300.00)
//        {
//            cout << "failed transaction\n";
//        }
//        else
//        {
//            amount -= 300.00;
//            balance_B += 300.00;
//            cout << "sucsesful transaction\n";
//        }
//
//    }
//    break;
//
//    case 3:
//    {
//
//        if (amount < 500.00)
//        {
//            cout << "failed transaction\n";
//        }
//        else
//        {
//            amount -= 500.00;
//            balance_B += 500.00;
//            cout << "sucsesful transaction\n";
//        }
//
//    }
//    break;
//
//    case 4:
//    {
//
//        if (amount < 1000.00)
//        {
//            cout << "failed transaction\n";
//        }
//        else
//        {
//            amount -= 1000.00;
//            balance_B += 1000.00;
//            cout << "sucsesful transaction\n";
//        }
//
//    }
//    break;
//
//    case 5:
//    {
//
//        if (amount < 2000.00)
//        {
//            cout << "failed transaction\n";
//        }
//        else
//        {
//            amount -= 2000.00;
//            balance_B += 2000.00;
//            cout << "sucsesful transaction\n";
//        }
//
//    }
//    break;
//
//    case 6:
//    {
//        double trans = 0;
//        cout << "Enter the amount you want to tranfer\n";
//        cout << "\t max : 10k\n";
//        cout << "\t min : 50\n";
//        cin >> trans;
//        if (amount < trans || trans > 10000.00 || trans < 50.00)
//        {
//            cout << "failed transaction\n";
//        }
//        else
//        {
//            amount -= trans;
//            balance_B += trans;
//            cout << "sucsesful transaction\n";
//        }
//
//    }
//    break;
//
//    default:
//        cout << "invaled number\n";
//        break;
//    }
//}

Transfer::Transfer(Account accountFrom, Account accountTo)
{
	this->accountFrom = accountFrom;
	this->accountTo = accountTo;
}

Account Transfer::getAccountFrom() const
{
	return this->accountFrom;
}

Account Transfer::getAccountTo() const
{
	return this->accountTo;
}

void Transfer::setAccountFrom(Account accountFrom)
{
	this->accountFrom = accountFrom;
}

void Transfer::setAccountTo(Account accountTo)
{
	this->accountTo = accountTo;
}

void Transfer::setAmount(double amount)
{
	this->amount = amount;
}










