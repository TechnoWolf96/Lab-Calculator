#pragma once
#include <string>
#include "TStack.h"
#include <math.h>
#define VIRGULE '.'		// ����� ������ �������� �������-������������ ����� � ������� ����� ������������ �����

using namespace std;

class TCalculator
{
private:
	string expression;				// �������������� ���������
	string postfix;					// ����������� ������ ���������
	TStack<double> numberStack;		// ���� � �������
	TStack<char> operatorStack;		// ���� � ����������� � ��������

	const string operators = "+-/*^";		// ������ �� ������������� �����������


	void ToPostfix();				// ��������� ����������� ������ � ������ postfix
	int Priority(char oper);		// ���������� ��������� ��������
	bool CheckExpression();			// ������� �������� ���������� ���������
	bool IsOperator(char symbol);	// ������� ���������, ���� �� ���������� ���������� ������
	void ClearStacks();				// ������� ������

public:

	TCalculator(string expression = "");				// �����������
	TCalculator(const TCalculator& other);				// ����������� �����������
	~TCalculator() {}									// ����������
	TCalculator& operator=(const TCalculator& other);	// ������������
	void SetExpression(string expression);				// ������
	string GetExpression() { return expression; }		// ������
	string GetPostfix() { return postfix; }				// �������� ����������� ������
	
	double CalculatePostfix();	// ���������� �������� ���������, ��������� ������ postfix
	double Calculate();			// ���������� ��������� ��� ������������� ������� �������������� ������ postfix
};

inline void TCalculator::ClearStacks()
{
	numberStack.Clear();
	operatorStack.Clear();
}

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
	numberStack = TStack<double>(expression.size());
	operatorStack = TStack<char>(expression.size());
	if (!CheckExpression()) throw "Wrong expression";
	ToPostfix();
	
}

inline TCalculator::TCalculator(const TCalculator& other)
{
	expression = other.expression;
	postfix = other.postfix;
	numberStack = TStack<double>(other.expression.size());
	operatorStack = TStack<char>(other.expression.size());

}

inline TCalculator& TCalculator::operator=(const TCalculator& other)
{
	expression = other.expression;
	postfix = other.postfix;
	numberStack = other.numberStack;
	operatorStack = other.operatorStack;
}

inline void TCalculator::SetExpression(string expression)
{
	this->expression = expression;
	if (!CheckExpression()) throw "Wrong expression";
	ToPostfix();
	numberStack.~TStack();
	operatorStack.~TStack();
	numberStack = TStack<double>(expression.size());
	operatorStack = TStack<char>(expression.size());
}

inline bool TCalculator::CheckExpression()
{
	ClearStacks();

	// ��������� ��� ��������� - ��� ������������������: �����, ��������, �����, �������� � �.� (������ ����������)
	for (int i = 0; i < expression.size(); i++)
	{
		if (!isdigit(expression[i]) && !IsOperator(expression[i]) && expression[i] != '('
			&& expression[i] != ')' && expression[i] != ' ') return false;
		if (isdigit(expression[i]))
		{
			size_t addIndex;
			operatorStack.Push('n');
			stod(&expression[i], &addIndex);
			if (operatorStack.Count() > 1)
				return false;
			i += addIndex;
		}
		
		if (IsOperator(expression[i]))
		{
			try { operatorStack.Pop(); }
			catch (...) { return false; }
		}
		if (operatorStack.Count() > 1)
			return false;
	}
	ClearStacks();
	// �������� ������������ ����������� ������
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '(') operatorStack.Push('(');
		try
		{
			if (expression[i] == ')') operatorStack.Pop();
		}
		catch (...)
		{
			return false;
		}
	}
	if (!operatorStack.Empty()) return false;
	return true;
}

inline double TCalculator::CalculatePostfix()
{
	ClearStacks();
	for (int i = 0; i < postfix.length(); i++)
	{
		if (isdigit(postfix[i])) // ���� � ����������� ������ �������� ����� ��:
		{
			size_t addIndex;
			double number = stod(&postfix[i], &addIndex);
			numberStack.Push(number);	// ��������� ��� � ���� � �������
			i += addIndex;	// ��������� ������� ������ �� ������ ��������� ��������/��������
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

inline double TCalculator::Calculate()
{
	ClearStacks();
	string infix = '(' + expression + ')';
	for (int i = 0; i < infix.length(); i++)
	{
		if (isdigit(infix[i])) // ���� � ����������� ������ �������� ����� ��:
		{
			size_t addIndex;
			double number = stod(&infix[i], &addIndex);
			numberStack.Push(number);	// ��������� ��� � ���� � �������
			i += addIndex;	// ��������� ������� ������ �� ������ ��������� ��������/��������
		}
		if (infix[i] == '(') // ����������� ������ - ������ � ���� ��������
			operatorStack.Push(infix[i]);
			
		if (IsOperator(infix[i]))	// ���������� ��������
		{
			// �������� �����/���������������� �������� - ��������� ��, ��� �� ������� �����
			while (Priority(infix[i]) <= Priority(operatorStack.Top())) 
			{
				double second = numberStack.Pop();
				double first = numberStack.Pop();
				switch (operatorStack.Pop())
				{
				case '+': numberStack.Push(first + second); break;
				case '-': numberStack.Push(first - second); break;
				case '*': numberStack.Push(first * second); break;
				case '/': numberStack.Push(first / second); break;
				case '^': numberStack.Push(pow(first, second)); break;
				}
			}
			// � ������ � ���� ����� ��������
			operatorStack.Push(infix[i]);
		}
		if (infix[i] == ')')	// ����������� ����������� ������ - ��������� �������� � ����� �� ����������� ������
		{
			while (operatorStack.Top() != '(')
			{
				double second = numberStack.Pop();
				double first = numberStack.Pop();
				switch (operatorStack.Pop())
				{
				case '+': numberStack.Push(first + second); break;
				case '-': numberStack.Push(first - second); break;
				case '*': numberStack.Push(first * second); break;
				case '/': numberStack.Push(first / second); break;
				case '^': numberStack.Push(pow(first, second)); break;
				}
			}
			operatorStack.Pop(); // ������ ����������� ������
		}

	}
	return numberStack.Pop();
}

inline void TCalculator::ToPostfix()
{
	ClearStacks();
	string infix = "(" + expression + ")";
	postfix = "";
	for (int i = 0; i < infix.size(); i++)
	{
		if (isdigit(infix[i]))	// ��������� �����
		{
			// ��������� ��������� ������������ ����� (���� � ���� 10e5, 10e-5)
			while ((isdigit(infix[i]) || infix[i] == VIRGULE || infix[i] == 'e' ||
				(i > 0 && infix[i - 1] == 'e' && infix[i] == '-')) && i < infix.size())
			{
				postfix += infix[i];
				i++;
			}
			postfix += ' ';
		}
		if (infix[i] == '(') operatorStack.Push(infix[i]);
		if (infix[i] == ')')
		{
			while (operatorStack.Top() != '(')
				postfix = postfix + operatorStack.Pop() + ' ';
			operatorStack.Pop();
		}
		if (IsOperator(infix[i]))
		{
			while (Priority(infix[i]) <= Priority(operatorStack.Top()))
			{
				postfix = postfix + operatorStack.Pop() + ' ';
			}
			operatorStack.Push(infix[i]);
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