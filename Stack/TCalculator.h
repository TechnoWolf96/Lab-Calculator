#pragma once
#include <string>
#include "TStack.h"
#include <math.h>

using namespace std;

class TCalculator
{
private:
	string expression;				// Алгебраическое выражение
	string postfix;					// Постфиксная запись выражения
	TStack<char> charStack;			// Стек для формирования постфиксной записи
	TStack<double> numberStack;		// Стек с постфиксной записью

	void ToPostfix();
	int Priority(char oper);
	bool CheckExpression();

	const string operators = "+-/*^";			// Строка со всевозможными операторами
	bool IsOperator(char symbol);			// Функция проверяет, есть ли оператором переданный символ

public:

	TCalculator(string expression = "");				// Конструктор
	TCalculator(const TCalculator& other);				// Конструктор копирования
	~TCalculator() {}									// Деструктор
	TCalculator& operator=(const TCalculator& other);	// Присваивание
	void Set(string expression);						// Сеттер
	string Get() { return expression; }					// Геттер
	string GetPostfix() { return postfix; }				// Получить постфиксную запись
	
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
	* Написать реализацию перестройки постфиксной записи
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
		if (isdigit(postfix[i])) // Если в постфиксной записи попалось число то:
		{
			char a[1]; a[0] = postfix[i];
			numberStack.Push(atof(a));	// Добавляем его в стек с числами
			continue;	
		}
			
		if (IsOperator(postfix[i]))	// Встретился знак - нужно произвести данную операцию над двумя последними в стеке числами
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