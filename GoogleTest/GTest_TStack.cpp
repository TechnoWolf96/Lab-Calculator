#include "pch.h"
#include "../Stack/TCalculator.h"

TEST(TStack, Can_create_stack_witn_positive_size)
{
	EXPECT_NO_THROW(TStack<int> stack(5));
}
TEST(TStack, Can_not_create_stack_witn_negative_size)
{
	EXPECT_ANY_THROW(TStack<int> stack(-1));
}
TEST(TStack, Stack_is_empty_during_creating)
{
	TStack<int> a(1);
	EXPECT_TRUE(a.Empty());
}
TEST(TStack, Check_working_equal_operator)
{
	TStack<int> a(3); TStack<int> b;
	a.Push(1); a.Push(2); a.Push(3);
	b = a;
	EXPECT_TRUE(a == b);
}
TEST(TStack, Stacks_have_own_memory)
{
	TStack<int> a(3); TStack<int> b;
	a.Push(1); a.Push(2); a.Push(3);
	b = a;
	b.Pop();
	b.Push(4);
	EXPECT_TRUE(a != b);
}
TEST(TStack, Can_put_element)
{
	TStack<int> a(1);
	a.Push(1);
	EXPECT_EQ(1, a.Top());
}
TEST(TStack, Stack_is_not_epmty_when_put_element)
{
	TStack<int> a(1);
	a.Push(1);
	EXPECT_FALSE(a.Empty());
}
TEST(TStack, Stack_become_empty_when_extract_last_element)
{
	TStack<int> a(1);
	a.Push(1);
	a.Pop();
	EXPECT_TRUE(a.Empty());
}
TEST(TStack, Stack_is_full_when_stack_have_not_memory)
{
	TStack<int> a(2);
	a.Push(1); a.Push(2);
	EXPECT_TRUE(a.Full());
}
TEST(TStack, Can_not_put_element_in_overflow_stack)
{
	TStack<int> a(2);
	a.Push(1); a.Push(2);
	EXPECT_ANY_THROW(a.Push(3));
}
TEST(TStack, Can_not_extract_element_when_stack_is_empty)
{
	TStack<int> a(3);
	EXPECT_ANY_THROW(a.Pop());
}
TEST(TStack, Can_not_check_element_when_stack_is_empty)
{
	TStack<int> a(3);
	EXPECT_ANY_THROW(a.Top());
}
TEST(TStack, Check_counter)
{
	TStack<int> a(5);
	a.Push(1); a.Push(2); a.Push(3);
	EXPECT_EQ(3, a.Count());
}
TEST(TStack, Stack_is_empty_when_worked_clear)
{
	TStack<int> a(5);
	a.Push(1); a.Push(2); a.Push(3);
	a.Clear();
	EXPECT_TRUE(a.Empty());
}
