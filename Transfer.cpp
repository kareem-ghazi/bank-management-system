#include "Transfer.h"

void Transfer::main_menu()
{
    int choose = 0;
    /*double temp = 0;*/
    //cout << "wright you card number\n";
    //cout << "wright the card number you want to transfer to\n";

    cout << "=======\t\t Trasfer menu \t\t=======\n\n";
    cout << "     [1] 100 \t [2] 300 \t [3] 500\t\n\n";
    cout << "     [4] 1000 \t [5] 2000 \t [6] other\n";
    cin >> choose;

    switch (choose)
    {
    case 1:
    {

        if (balance < 100.00)
        {
            cout << "failed transaction\n";
        }
        else
        {
            balance -= 100.00;
            balance_B += 100.00;
            cout << "sucsesful transaction\n";
        }

    }
    break;

    case 2:
    {

        if (balance < 300.00)
        {
            cout << "failed transaction\n";
        }
        else
        {
            balance -= 300.00;
            balance_B += 300.00;
            cout << "sucsesful transaction\n";
        }

    }
    break;

    case 3:
    {

        if (balance < 500.00)
        {
            cout << "failed transaction\n";
        }
        else
        {
            balance -= 500.00;
            balance_B += 500.00;
            cout << "sucsesful transaction\n";
        }

    }
    break;

    case 4:
    {

        if (balance < 1000.00)
        {
            cout << "failed transaction\n";
        }
        else
        {
            balance -= 1000.00;
            balance_B += 1000.00;
            cout << "sucsesful transaction\n";
        }

    }
    break;

    case 5:
    {

        if (balance < 2000.00)
        {
            cout << "failed transaction\n";
        }
        else
        {
            balance -= 2000.00;
            balance_B += 2000.00;
            cout << "sucsesful transaction\n";
        }

    }
    break;

    case 6:
    {
        double trans = 0;
        cout << "Enter the amount you want to tranfer\n";
        cout << "\t max : 10k\n";
        cout << "\t min : 50\n";
        cin >> trans;
        if (balance < trans || trans > 10000.00 || trans < 50.00)
        {
            cout << "failed transaction\n";
        }
        else
        {
            balance -= trans;
            balance_B += trans;
            cout << "sucsesful transaction\n";
        }

    }
    break;

    default:
        cout << "invaled number\n";
        break;
    }
}

