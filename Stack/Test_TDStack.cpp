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

	cout << "���� ��������? �����: " << dStack.Full() << endl;

	cout << "\n��������� �������� �� 1 �����: ";
	while (!dStack.Empty1())
	{
		int temp = dStack.Pop1();
		cout << "\n�������� ������� �� 1 �����: " << temp << " ; ���� ��������? �����: "
			<< dStack.Full() << " ; ���� 1 ����? �����: " << dStack.Empty1();
	}
	cout << "\n��������� �������� �� 2 �����: ";
	while (!dStack.Empty2())
	{
		int temp = dStack.Pop2();
		cout << "\n�������� ������� �� 2 �����: " << temp << " ; ���� ��������? �����: "
			<< dStack.Full() << " ; ���� 2 ����? �����: " << dStack.Empty2();
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
