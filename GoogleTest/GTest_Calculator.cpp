#include "pch.h"
#include "../Stack/TCalculator.h"

TEST(TCalculator, Can_create_calculator_with_correct_expression)
{
	ASSERT_NO_THROW(TCalculator a("1+2*3^4"));
}
TEST(TCalculator, Can_not_create_calculator_with_uncorrect_expression)
{
	ASSERT_NO_THROW(TCalculator a(")(1+2*3^4"));
	ASSERT_NO_THROW(TCalculator a(")4)"));
	ASSERT_NO_THROW(TCalculator a("4+2+-4"));
}
TEST(TCalculator, True_Calculate_1)
{
	const double error = 10e-7;	
	TCalculator a("2+4^9*9-7/2+3");
	EXPECT_TRUE(abs(2359297.5 - a.Calculate()) < error);
}
TEST(TCalculator, True_Calculate_2)
{
	const double error = 10e-7;
	TCalculator a("2*(5*3-8)*2^5/6");
	EXPECT_TRUE(abs(74.66666667 - a.Calculate()) < error);
}
TEST(TCalculator, True_Calculate_3)
{
	const double error = 10e-7;
	TCalculator a("(5+9*8)/((5+6)*2^4)");
	EXPECT_TRUE(abs(0.4375 - a.Calculate()) < error);
}