#pragma once
#include <string>
#include "TStack.h"

using namespace std;

class TCalculator
{
private:
	string expression;
	string postfix;
	TStack<char> charStack;
	TStack<double> numberStack;

public:
	// Constructor
	// Destructor
	// Set/Get expression

	bool CheckExpression()
	{

		return true;
	}

	double Calculate()
	{
		for (int i = 0; i < postfix.length(); i++)
		{
			//isdigit()
			if (postfix[i] >= '0' && postfix[i] <= '9')
				numberStack.Push(stod(&postfix[i]));
			if (postfix[i] == '+' || postfix[i] == '-')
			{
				double second = numberStack.Pop();
				double first = numberStack.Pop();
				switch (postfix[i])
				{
				case '+':
				{
					numberStack.Push(first + second);
				}
				break;

				case '-':
				{
					numberStack.Push(first - second);
				}
				break;

				default:
					break;
				}
			}
		}
		return numberStack.Pop();
	}


};