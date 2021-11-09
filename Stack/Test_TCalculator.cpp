#include "TCalculator.h"
#include <iostream>
using namespace std;

void TestTCalculator()
{
    TCalculator a("5*9/8^(4-2)+(9-8)/5*2");
    cout << "Postfix: " << a.GetPostfix() << endl;
    cout << "Result: " << a.Calculate() << endl;
}


int main3()
{
    setlocale(LC_ALL, "ru");

    TestTCalculator();

    cout << endl;
    system("pause");
    return 0;
}