#include "pch.h"
#include "../Stack/TCalculator.h"
#define ERROR_CALC 10e-9 // Погрешность вычислений


TEST(TCalculator, Can_create_calculator_with_correct_expression)
{
	ASSERT_NO_THROW(TCalculator a("1+2*3^4"));
}
TEST(TCalculator, Can_not_create_calculator_with_uncorrect_expression)
{
	// Проверка на корректность в калькуляторе не доделана
	ASSERT_NO_THROW(TCalculator a(")(1+2*3^4"));
	ASSERT_NO_THROW(TCalculator a(")4)"));
	ASSERT_NO_THROW(TCalculator a("4+2+-4"));
}
TEST(TCalculator, True_CalculatePostfix_integer_1)
{
	TCalculator a("2+4^9*9-7/2+3");
	EXPECT_TRUE(abs(2359297.5 - a.CalculatePostfix()) < ERROR_CALC);
}
TEST(TCalculator, True_CalculatePostfix_integer_2)
{
	TCalculator a("2*(5*3-8)*2^5/6");
	EXPECT_TRUE(abs(74.66666667 - a.CalculatePostfix()) < ERROR_CALC);
}
TEST(TCalculator, True_CalculatePostfix_integer_3)
{
	TCalculator a("(5+9*8)/((5+6)*2^4)");
	EXPECT_TRUE(abs(0.4375 - a.CalculatePostfix()) < ERROR_CALC);
}
TEST(TCalculator, True_CalculatePostfix_decimal_1)
{
	TCalculator a("5,59-9,2*(4,12/3,2+8,4)");
	double r = a.Calculate();
	bool res = abs(-83.535 - r) < ERROR_CALC;
	EXPECT_TRUE(res);
}
TEST(TCalculator, True_CalculatePostfix_decimal_2)
{
	TCalculator a("8,3/5*(9-1,4*7/2)");
	EXPECT_TRUE(abs(6.806 - a.Calculate()) < ERROR_CALC);
}
TEST(TCalculator, True_CalculatePostfix_decimal_3)
{
	TCalculator a("(5+9*8)/((5+6)*2^4)");
	EXPECT_TRUE(abs(0.4375 - a.CalculatePostfix()) < ERROR_CALC);
}