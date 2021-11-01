#pragma once
#include <string>
#include "TStack.h"

using namespace std;

class TCalculator
{
private:
	string expression;				// �������������� ���������
	string postfix;					// ����������� ������ ���������
	TStack<char> charStack;			// ���� ��� ������ (��� �������� ������������ ���������)
	TStack<double> numberStack;		// ���� � ���������� �������

	const string operators = "+-/*";			// ������ �� ������������� �����������
	bool CheckOperator(char _operator);			// ������� ���������, ���� �� � ����������� ������ � ����������� ���������� ��������

public:

	TCalculator(string expression = "");				// �����������
	TCalculator(const TCalculator& other);				// ����������� �����������
	~TCalculator() {}									// ����������
	TCalculator& operator=(const TCalculator& other);	// ������������
	void Set(string expression);						// ������
	string Get() { return expression; }					// ������


	bool CheckExpression();
	double Calculate();

	

};


inline bool TCalculator::CheckOperator(char _operator)
{
	for (int i = 0; i < operators.length(); i++)
	{
		if (_operator == operators[i]) return true;
	}
	return false;
}

inline TCalculator::TCalculator(string expression)
{
	this->postfix = expression;
	if (!CheckExpression()) throw "Wrong expression";

	/*
	* �������� ���������� ������������ ���������
	*/
	
}

inline TCalculator::TCalculator(const TCalculator& other)
{
	expression = other.expression;
	postfix = other.postfix;

}

inline TCalculator& TCalculator::operator=(const TCalculator& other)
{
	expression = other.expression;
	postfix = other.postfix;
}

inline void TCalculator::Set(string expression)
{
	this->expression = expression;
	/*
	* �������� ���������� ����������� ����������� ������
	*/
}

inline bool TCalculator::CheckExpression()
{
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '(') charStack.Push('(');
		try
		{
			if (expression[i] == ')') charStack.Pop();
		}
		catch (...)
		{
			return false;
		}
	}
	if (!charStack.Empty()) return false;
	return true;
}

inline double TCalculator::Calculate()
{
	for (int i = 0; i < postfix.length(); i++)
	{
		if (isdigit(postfix[i]))					// ���� � ����������� ������ �������� ����� ��
		{
			char a[1]; a[0] = postfix[i];
			numberStack.Push(atof(a));	// ��������� ��� � ���� � �������
			continue;	
		}
			
		if (CheckOperator(postfix[i]))	// ���������� ���� - ����� ���������� ������ �������� ��� ����� ���������� � ����� �������
		{
			double second = numberStack.Pop();
			double first = numberStack.Pop();
			switch (postfix[i])
			{
			case '+': numberStack.Push(first + second); break;

			case '-': numberStack.Push(first - second); break;

			case '*': numberStack.Push(first * second); break;

			case '/': numberStack.Push(first / second); break;

			}
		}
	}
	return numberStack.Pop();
}
