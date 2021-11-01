#include <iostream>
#include <string>
#include "TStack.h"
using namespace std;

void TestTStack()
{
    int size = 5;
    int items[5] = { 1, 5, 2, 8, -12 };

    cout << "\n===== Тестирование класса TStack =====" << endl;

    TStack<int> a(size);
    for (int i = 0; i < size; i++) a.Push(items[i]);
    cout << "\nСтек А заполнен. a.Full() = " << a.Full() << ", a.Empty() = " << a.Empty() << ", a.Count() = " << a.Count();

    TStack<int> b(a);
    cout << "\nВ стек В скопирован стек А. b.Full() = " << b.Full() << ", b.Empty() = " << b.Empty() << ", b.Count() = " << b.Count();
    cout << "\nНа вершине А лежит: " << a.Top() << "; На вершине B лежит: " << b.Top();
    int q = b.Pop();
    cout << "\nИз В извлечен элемент " << q << "; На вершине B лежит: " << b.Top() << "; b.Full() = " << b.Full() << ", b.Empty() = " << b.Empty() << ", b.Count() = " << b.Count();
    cout << "\nСравнение: A!=B: " << (a != b) << "; A == B: " << (a == b);

    cout << "\nВ стеке А находились элементы: ";
    while (!a.Empty()) cout << a.Pop() << ' ';
    cout << "\nВ стеке В находились элементы: ";
    while (!b.Empty()) cout << b.Pop() << ' ';
    cout << "\nСтек А опустел. Full = " << a.Full() << ", Empty = " << a.Empty() << ", a.Count() = " << a.Count();
    cout << "\nСтек B опустел. Full = " << b.Full() << ", Empty = " << b.Empty() << ", a.Count() = " << b.Count();

    for (int i = 0; i < size; i++) a.Push(items[i]);
    cout << "\nСтек А заполнен. a.Full() = " << a.Full() << ", a.Empty() = " << a.Empty() << ", a.Count() = " << a.Count();
    a.Clear();
    cout << "\nСтек А: Применен Clear(). a.Full() = " << a.Full() << ", a.Empty() = " << a.Empty() << ", a.Count() = " << a.Count();

}





int _main()
{
    setlocale(LC_ALL, "ru");

    TestTStack();
    
    cout << endl;
    system("pause");
    return 0;
}

