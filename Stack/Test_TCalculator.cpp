#include "TCalculator.h"
#include <iostream>
using namespace std;

void TestTCalculator()
{
    TCalculator a("5a+24");
    cout << "Postfix: " << a.GetPostfix() << endl;
    double b = 1e-3;
    double res1 = a.Calculate();
    double res = a.CalculatePostfix();
    bool r = abs(-83.535 - a.CalculatePostfix()) < 10e-9;
    cout << "Result Postfix: " << a.CalculatePostfix() << endl;
    cout << "Result: " << a.Calculate() << endl;
}


int main()
{
    setlocale(LC_ALL, "eng");
    TestTCalculator();

    cout << endl;
    system("pause");
    return 0;
}