#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, can_create_vector_with_max_size)
{
    ASSERT_NO_THROW(TVector<int> v(MAX_VECTOR_SIZE));
}

TEST(TVector, can_create_vector_with_zero_size)
{
    ASSERT_NO_THROW(TVector<int> v(0));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(2, 0);
	v[1] = 2;
	TVector<int> pv(v);

	EXPECT_EQ(v,pv);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(2, 0);
	TVector<int> pv(v);
	pv[1] = 2;
	EXPECT_NE(pv[1], v[1]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);
  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[-22]=2);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(2);
	ASSERT_ANY_THROW(v[2] = 2);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4);
	v[3] = 5;
	EXPECT_EQ(v=v, v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> first(5), second(5);
	first = second;
	EXPECT_EQ(first, second);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> first(5), second(5);
	second[3] = 5;
	first = second;
	EXPECT_EQ(first, second);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> first(5), second(7);
	second[3] = 5;
	first = second;
	EXPECT_EQ(first, second);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> first(3), second(3);
	first[0] = 1;
	first[1] = 2;
	first[2] = 3;
	second = first;
	EXPECT_EQ(first, second);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> first(6);
	EXPECT_EQ(first, first);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> first(3);
	first[0] = 1;
	first[1] = 2;
	first[2] = 3;
	EXPECT_EQ(first, first);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> first(5), second(5);
	for (int i = 0; i < 5; i++)
	{
		first[i] = 2;
		second[i] = 10;
	}
	first = first + 8;
	EXPECT_EQ(first, second);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> first(5), second(5);
	for (int i = 0; i < 5; i++)
	{
		first[i] = 10;
		second[i] = 2;
	}
	first = first - 8;
	EXPECT_EQ(first, second);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> first(5), second(5);
	for (int i = 0; i < 5; i++)
	{
		first[i] = 2;
		second[i] = 10;
	}
	first = first*5;
	EXPECT_EQ(first, second);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> first(5), second(5), sum(5);
	for (int i = 0; i < 5; i++)
	{
		first[i] = i;
		second[i] = 8;
		sum[i] = 8 + i;
	}
	EXPECT_EQ(first + second, sum);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> first(11), second(6);
	ASSERT_ANY_THROW(first + second);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> first(5), second(5), sum(5);
	for (int i = 0; i < 5; i++)
	{
		first[i] = 8;
		second[i] = i;
		sum[i] = 8 - i;
	}
	EXPECT_EQ(first - second, sum);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> first(11), second(6);
	ASSERT_ANY_THROW(first - second);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> first(5), second(5);
	int mult = 0;
	for (int i = 0; i < 5; i++)
	{
		first[i] = 8;
		second[i] = i;
		mult = mult + 8 * i;
	}
	EXPECT_EQ(first * second, mult);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> first(11), second(6);
	ASSERT_ANY_THROW(first * second);
}

