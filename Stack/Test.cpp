#include <iostream>
#include <string>
#include "TStack.h"
using namespace std;

void Test()
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

bool BracketsTask(string str) // Задача про скобки, возвращает верно ли расставлены скобки
{
    TStack<char> stack(str.size());
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(') stack.Push('(');
        try
        {
            if (str[i] == ')') stack.Pop();
        }
        catch (...)
        {
            return false;
        }
    }
    if (!stack.Empty()) return false;
    return true;
}



int _main()
{
    setlocale(LC_ALL, "ru");

    string str;
    getline(cin, str);
    if (BracketsTask(str)) cout << "\nСкобки расставлены верно.";
    else cout << "\nСкобки расставлены неверно.";
    
    cout << '\n';
    system("pause");
    return 0;
}

