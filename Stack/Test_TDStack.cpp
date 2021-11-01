#include <iostream>
#include <string>
#include "TDStack.h"
using namespace std;

void TestTDStack()
{
	int arr1[5] = { 1, 2, 3, 4, 5 }; int size1 = 5;
	int arr2[5] = { 10, 9, 8, 7, 6 }; int size2 = 5;
	TDStack<int> dStack(10);
	for (int i = 0; i < size1; i++)
		dStack.Push1(arr1[i]);

	for (int i = 0; i < size2; i++)
		dStack.Push2(arr2[i]);

	cout << "Стек заполнен? Ответ: " << dStack.Full() << endl;

	cout << "\nИзвлечены элементы из 1 стека: ";
	while (!dStack.Empty1())
	{
		int temp = dStack.Pop1();
		cout << "\nИзвлечен элемент из 1 стека: " << temp << " ; Стек заполнен? Ответ: "
			<< dStack.Full() << " ; Стек 1 пуст? Ответ: " << dStack.Empty1();
	}
	cout << "\nИзвлечены элементы из 2 стека: ";
	while (!dStack.Empty2())
	{
		int temp = dStack.Pop2();
		cout << "\nИзвлечен элемент из 2 стека: " << temp << " ; Стек заполнен? Ответ: "
			<< dStack.Full() << " ; Стек 2 пуст? Ответ: " << dStack.Empty2();
	}
}




int __main()
{
	setlocale(LC_ALL, "ru");

	TestTDStack();

	cout << endl;
	system("pause");
	return 0;
}
