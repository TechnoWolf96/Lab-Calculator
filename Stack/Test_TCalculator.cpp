#include "TCalculator.h"
#include <iostream>
using namespace std;

void TestTCalculator()
{
    TCalculator a("2+4^9*9-7/2+3");
    cout << "Postfix: " << a.GetPostfix() << endl;
    double res1 = a.Calculate();
    double res = a.CalculatePostfix();
    bool r = abs(-83.535 - a.CalculatePostfix()) < 10e-9;
    cout << "Result Postfix: " << a.CalculatePostfix() << endl;
    cout << "Result: " << a.Calculate() << endl;
}


int main()
{
    setlocale(LC_ALL, "ru");
    TestTCalculator();

    cout << endl;
    system("pause");
    return 0;
}