#include "TCalculator.h"
#include <iostream>
using namespace std;

void TestTCalculator()
{
    TCalculator a("5,59-9,2*(4,12/3,2+8,4)");
    cout << "Postfix: " << a.GetPostfix() << endl;
    double res1 = a.CalculatePostfix();
    double res = abs(-83.535 - a.CalculatePostfix());
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