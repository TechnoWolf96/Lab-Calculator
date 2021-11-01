#pragma once
#include <string>
#include "TStack.h"

using namespace std;

class TCalculator
{
private:
	string expression;				// Алгебраическое выражение
	string postfix;					// Постфиксная запись выражения
	TStack<char> charStack;			// Стек для скобок (Для проверки корректности выражения)
	TStack<double> numberStack;		// Стек с посфиксной записью

	const string operators = "+-/*";			// Строка со всевозможными операторами
	bool CheckOperator(char _operator);			// Функция проверяет, есть ли в константной строке с операторами переданный оператор

public:

	TCalculator(string expression = "");				// Конструктор
	TCalculator(const TCalculator& other);				// Конструктор копирования
	~TCalculator() {}									// Деструктор
	TCalculator& operator=(const TCalculator& other);	// Присваивание
	void Set(string expression);						// Сеттер
	string Get() { return expression; }					// Геттер


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
	* Написать реализацию постфиксного выражения
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
		if (isdigit(postfix[i]))					// Если в постфиксной записи попалось число то
		{
			char a[1]; a[0] = postfix[i];
			numberStack.Push(atof(a));	// Добавляем его в стек с числами
			continue;	
		}
			
		if (CheckOperator(postfix[i]))	// Встретился знак - нужно произвести данную операцию над двумя последними в стеке числами
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
