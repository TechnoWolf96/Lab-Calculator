#pragma once
#include <string>
#include "TStack.h"
#include <math.h>

using namespace std;

class TCalculator
{
private:
	string expression;				// �������������� ���������
	string postfix;					// ����������� ������ ���������
	TStack<char> charStack;			// ���� ��� ������������ ����������� ������
	TStack<double> numberStack;		// ���� � ����������� �������

	void ToPostfix();
	int Priority(char oper);
	bool CheckExpression();

	const string operators = "+-/*^";			// ������ �� ������������� �����������
	bool IsOperator(char symbol);			// ������� ���������, ���� �� ���������� ���������� ������

public:

	TCalculator(string expression = "");				// �����������
	TCalculator(const TCalculator& other);				// ����������� �����������
	~TCalculator() {}									// ����������
	TCalculator& operator=(const TCalculator& other);	// ������������
	void Set(string expression);						// ������
	string Get() { return expression; }					// ������
	string GetPostfix() { return postfix; }				// �������� ����������� ������
	
	double Calculate();
};
inline bool TCalculator::IsOperator(char symbol)
{
	for (int i = 0; i < operators.length(); i++)
	{
		if (symbol == operators[i]) return true;
	}
	return false;
}


inline TCalculator::TCalculator(string expression)
{
	this->expression = expression;
	charStack = TStack<char>(expression.size());
	if (!CheckExpression()) throw "Wrong expression";
	ToPostfix();
	
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
		if (isdigit(postfix[i])) // ���� � ����������� ������ �������� ����� ��:
		{
			char a[1]; a[0] = postfix[i];
			numberStack.Push(atof(a));	// ��������� ��� � ���� � �������
			continue;	
		}
			
		if (IsOperator(postfix[i]))	// ���������� ���� - ����� ���������� ������ �������� ��� ����� ���������� � ����� �������
		{
			double second = numberStack.Pop();
			double first = numberStack.Pop();
			switch (postfix[i])
			{
			case '+': numberStack.Push(first + second); break;
			case '-': numberStack.Push(first - second); break;
			case '*': numberStack.Push(first * second); break;
			case '/': numberStack.Push(first / second); break;
			case '^': numberStack.Push(pow(first, second)); break;
			}
		}
	}
	return numberStack.Pop();
}

inline void TCalculator::ToPostfix()
{
	string infix = "(" + expression + ")";
	postfix = "";
	for (int i = 0; i < infix.size(); i++)
	{
		if (isdigit(infix[i])) postfix = postfix + infix[i] + ' ';
		if (infix[i] == '(') charStack.Push(infix[i]);
		if (infix[i] == ')')
		{
			while (charStack.Top() != '(')
				postfix = postfix + charStack.Pop() + ' ';
			charStack.Pop();
		}
		if (IsOperator(infix[i]))
		{
			while (Priority(infix[i]) <= Priority(charStack.Top()))
			{
				postfix = postfix + charStack.Pop() + ' ';
			}
			charStack.Push(infix[i]);
		}

	}

}
inline int TCalculator::Priority(char oper)
{
	if (oper == '(') return 0;
	if (oper == '+' || oper == '-') return 1;
	if (oper == '*' || oper == '/') return 2;
	if (oper == '^') return 3;
}