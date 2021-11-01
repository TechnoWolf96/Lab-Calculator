#include "TCalculator.h"
#include <iostream>
using namespace std;

void TestTCalculator()
{
    TCalculator a("67*");
    cout << a.Calculate();
}


int main()
{
    setlocale(LC_ALL, "ru");

    TestTCalculator();

    cout << endl;
    system("pause");

}