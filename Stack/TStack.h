#pragma once



// ����� "����" �� ���������� �������� ��������� � �������
template<class T>
class TStack
{
private:
	T* arr;			// ������, � ������� �������� �������� �����
	int size;		// ������ �����
	int pos;		// ������� ���������� �������� � �����
public:

	TStack(int _size = 10);						// �����������
	TStack(const TStack& other);				// ����������� �����������
	TStack<T>& operator=(const TStack<T>& other);	// �������� ������������
	~TStack() { delete[] arr; }					// ����������

	int Count() { return pos + 1; }				// ���������� ��������� � �����
	bool Empty();								// ������ �� ����
	bool Full();								// �������� �� ����
	void Push(T item);							// �������� ������� � ����
	T Pop();									// ������� ��������� ������� �� �����
	T Top();									// ���������� ��������� ������� � �����
	void Clear() { pos = -1; }					// �������� ����

	bool operator!=(const TStack<T>& other);		// ��������� ���������
	bool operator==(const TStack<T>& other);
	
};

template<class T>
inline TStack<T>::TStack(int _size)
{
	if (_size <= 0) throw "Wrong size";
	size = _size;
	arr = new T[size];
	pos = -1;
}

template<class T>
inline TStack<T>::TStack(const TStack& other)
{
	size = other.size;
	arr = new T[size];
	pos = other.pos;
	for (int i = 0; i <= pos; i++)
		arr[i] = other.arr[i];
}

template<class T>
inline bool TStack<T>::Empty()
{

	if (pos == -1) return true;
	else return false;
}

template<class T>
inline bool TStack<T>::Full()
{
	return pos >= size-1;
}

template<class T>
inline void TStack<T>::Push(T item)
{
	if (Full()) throw "Stack owerflow";
	arr[++pos] = item;
}
// ������� ��������� ������� �� �����
template<class T>
inline T TStack<T>::Pop() 
{
	if (Empty()) throw "Stack is empty";
	T temp = arr[pos];
	pos--;
	return temp;
}

template<class T>
inline T TStack<T>::Top()
{
	if (Empty()) throw "Stack is empty";
	return arr[pos];
}

template<class T>
inline TStack<T>& TStack<T>::operator=(const TStack<T>& other)
{
	if (size != other.size)
	{
		delete[] arr;
		size = other.size;
		arr = new T[size];
	}
	pos = other.pos;
	for (int i = 0; i <= pos; i++)
		arr[i] = other.arr[i];
	return *this;
}

template<class T>
inline bool TStack<T>::operator!=(const TStack& other)
{
	return !operator==(other);
}

template<class T>
inline bool TStack<T>::operator==(const TStack& other)
{
	if (pos != other.pos) return false;
	for (int i = 0; i <= pos; i++)
		if (arr[i] != other.arr[i]) return false;
	return true;
}
