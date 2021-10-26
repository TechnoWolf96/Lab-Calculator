#pragma once
// ����� "������� ����" �� ���������� �������� ���� ��������� ������ � �������
template<class T>
class TDStack
{
private:
	T* arr;			// ������, � ������� �������� �������� �����
	int size;		// ������ �����
	int top1;		// ������� ���������� �������� � ����� 1
	int top2;		// ������� ���������� �������� � ����� 2

public:

	TDStack(int _size = 10);						// �����������
	TDStack(const TDStack& other);					// ����������� �����������
	TDStack<T>& operator=(const TDStack<T>& other);	// �������� ������������
	~TDStack() { delete[] arr; }					// ����������


	bool Empty1() { return top1 == -1; }			// ������ �� 1 ����
	bool Empty2() { return top2 == size; }			// ������ �� 2 ����
	bool Full() { return top1 == top2 - 1; }		// ����������� �� ������ ��� �����

	void Push1(T item);							// �������� ������� � ���� 1
	void Push2(T item);							// �������� ������� � ���� 2
	T Pop1();									// ������� ��������� ������� �� ����� 1
	T Pop2();									// ������� ��������� ������� �� ����� 2
	T Top1();									// ���������� ��������� ������� � ����� 1
	T Top2();									// ���������� ��������� ������� � ����� 2
	void Clear() { top1 = -1; top2 = size; }	// �������� ����


};

template<class T>
inline TDStack<T>::TDStack(int _size)
{
	if (_size <= 0) throw "Wrong size";
	size = _size;
	arr = new T[size];
	top1 = -1;			// ���� 1 ����
	top2 = size;		// ���� 2 ����
}

template<class T>
inline TDStack<T>::TDStack(const TDStack<T>& other)
{
	size = other.size;
	arr = new T[size];
	top1 = other.top1;
	top2 = other.top2;

	for (int i = 0; i <= top1; i++)
		arr[i] = other.arr[i];

	for (int i = size-1; i >= top2; i--)
		arr[i] = other.arr[i];
}

template<class T>
inline TDStack<T>& TDStack<T>::operator=(const TDStack<T>& other)
{
	if (size != other.size)
	{
		delete[] arr;
		size = other.size;
		arr = new T[size];
	}

	top1 = other.top1;
	top2 = other.top2;

	for (int i = 0; i <= top1; i++)
		arr[i] = other.arr[i];

	for (int i = size - 1; i >= top2; i--)
		arr[i] = other.arr[i];

	return *this;
}

template<class T>
inline void TDStack<T>::Push1(T item)
{
	if (Full()) throw "Stack owerflow";
	arr[++top1] = item;
}

template<class T>
inline void TDStack<T>::Push2(T item)
{
	if (Full()) throw "Stack owerflow";
	arr[--top2] = item;
}

template<class T>
inline T TDStack<T>::Pop1()
{
	if (Empty1()) throw "Stack is empty";
	T temp = arr[top1];
	top1--;
	return temp;
}

template<class T>
inline T TDStack<T>::Pop2()
{
	if (Empty2()) throw "Stack is empty";
	T temp = arr[top2];
	top2++;
	return temp;
}

template<class T>
inline T TDStack<T>::Top1()
{
	if (Empty1()) throw "Stack1 is empty";
	return arr[top1];
}

template<class T>
inline T TDStack<T>::Top2()
{
	if (Empty2()) throw "Stack2 is empty";
	return arr[top2];
}



