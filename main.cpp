#include <iostream>

#include "Account.h"
#include "Person.h"
#include "Transfer.h"
#include "Database.h"
#include "BankManager.h"

using namespace std;

int main()
{
    BankManager p1;
    p1.setvalue();

    cout << "Result: " << p1.result() << endl;
    return 0;
}