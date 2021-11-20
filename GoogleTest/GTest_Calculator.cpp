#include "pch.h"
#include "../Stack/TCalculator.h"
#define ERROR_CALC 10e-9 // Погрешность вычислений


TEST(TCalculator, Can_create_calculator_with_correct_expression)
{
	ASSERT_NO_THROW(TCalculator a("()(1)+(2*(3^4))"));
}
TEST(TCalculator, Can_not_create_calculator_with_uncorrect_expression)
{
	ASSERT_ANY_THROW(TCalculator a(")(1+2*3^4"));
	ASSERT_ANY_THROW(TCalculator a(")4)"));
	ASSERT_ANY_THROW(TCalculator a("4+2+-4"));
	ASSERT_ANY_THROW(TCalculator a("5+5,,34"));
	ASSERT_ANY_THROW(TCalculator a("5/ +24"));
	ASSERT_ANY_THROW(TCalculator a("5 6/ +24"));
}
TEST(TCalculator, True_Calculate_integer_1)
{
	TCalculator a("2+4^9*9-7/2+3");
	EXPECT_TRUE(abs(2359297.5 - a.Calculate()) < ERROR_CALC);
	EXPECT_TRUE(abs(2359297.5 - a.CalculatePostfix()) < ERROR_CALC);
}
TEST(TCalculator, True_Calculate_integer_2)
{
	TCalculator a("2*(5*3-8)*2^5/6");
	EXPECT_TRUE(abs(74.666666667 - a.Calculate()) < ERROR_CALC);
	EXPECT_TRUE(abs(74.666666667 - a.CalculatePostfix()) < ERROR_CALC);
}
TEST(TCalculator, True_Calculate_integer_3)
{
	TCalculator a("(5+9*8)/((5+6)*2^4)");
	EXPECT_TRUE(abs(0.4375 - a.Calculate()) < ERROR_CALC);
	EXPECT_TRUE(abs(0.4375 - a.CalculatePostfix()) < ERROR_CALC);
}
TEST(TCalculator, True_Calculate_decimal_1)
{
	TCalculator a("5.59-9.2*(4.12/3.2+8.4)");
	EXPECT_TRUE(abs(-83.535 - a.Calculate()) < ERROR_CALC);
	EXPECT_TRUE(abs(-83.535 - a.CalculatePostfix()) < ERROR_CALC);
}
TEST(TCalculator, True_Calculate_decimal_2)
{
	TCalculator a("8.3/5*(9-1.4*7/2)");
	EXPECT_TRUE(abs(6.806 - a.Calculate()) < ERROR_CALC);
	EXPECT_TRUE(abs(6.806 - a.CalculatePostfix()) < ERROR_CALC);
}
TEST(TCalculator, True_Calculate_decimal_3)
{
	TCalculator a("8.9*4.15+(85.1/(4.2-1.3))-5.2");
	EXPECT_TRUE(abs(61.0798275862068 - a.Calculate()) < ERROR_CALC);
	EXPECT_TRUE(abs(61.0798275862068 - a.CalculatePostfix()) < ERROR_CALC);
}
TEST(TCalculator, True_Calculate_exponential_1)
{
	TCalculator a("5e3 * (1e-3 + 8e-2) / 8e2 + 24e-4");
	EXPECT_TRUE(abs(0.50865 - a.Calculate()) < ERROR_CALC);
	EXPECT_TRUE(abs(0.50865 - a.CalculatePostfix()) < ERROR_CALC);
}
TEST(TCalculator, True_Calculate_exponential_2)
{
	TCalculator a("12e3 - 10^5 / (8.26 + 71e-4)");
	EXPECT_TRUE(abs(-96.14012168716962 - a.Calculate()) < ERROR_CALC);
	EXPECT_TRUE(abs(-96.14012168716962 - a.CalculatePostfix()) < ERROR_CALC);
}
TEST(TCalculator, True_Calculate_exponential_3)
{
	TCalculator a("7.56e3 / 2^7 * (8.1e4 - 5126e-3)");
	EXPECT_TRUE(abs(4783759.745625 - a.Calculate()) < ERROR_CALC);
	EXPECT_TRUE(abs(4783759.745625 - a.CalculatePostfix()) < ERROR_CALC);
}
TEST(TCalculator, True_Calculate_strange_expression)
{
	TCalculator a("()(  1.25)    +94  * ()() 11e2-2^12");
	EXPECT_TRUE(abs(99305.25 - a.Calculate()) < ERROR_CALC);
	EXPECT_TRUE(abs(99305.25 - a.CalculatePostfix()) < ERROR_CALC);
}