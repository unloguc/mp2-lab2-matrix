#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	m[0][3] = 5;
	TMatrix<int> mp(m);

	EXPECT_EQ(m, mp);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> first(5);
	first[0][3] = 5;
	TMatrix<int> second(first);
	second[0][3] = 2;
	EXPECT_NE(first, second);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> first(5);
	EXPECT_EQ(first.GetSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> first(6);
	first[0][3] = 5;
	EXPECT_EQ(first[0][3], 5);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> first(6);
	ASSERT_ANY_THROW(first[-1][2]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> first(6);
	ASSERT_ANY_THROW(first[MAX_MATRIX_SIZE][2]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> first(2);
	first[0][0] = 1;
	first[0][1] = 1;
	first[1][1] = 3;
	EXPECT_EQ(first, first = first);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> first(2), second(2);
	first[0][0] = 1;
	first[0][1] = 1;
	first[1][1] = 3;
	second = first;
	EXPECT_EQ(first, second);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> first(2), second(7);
	first = second;
	EXPECT_EQ(first.GetSize(), 7);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> first(2), second(7);
	first = second;
	EXPECT_EQ(first, second);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> first(2), second(2);
	first[0][0] = 1;
	first[0][1] = 1;
	first[1][1] = 3;
	second[0][0] = 1;
	second[0][1] = 1;
	second[1][1] = 3;
	EXPECT_EQ(first, second);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> first(2);
	EXPECT_EQ(first, first);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> first(2), second(4);
	EXPECT_NE(first, second);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> first(6), second(6), sum(6);
	for (int i = 0; i < 6; i++)
		for (int j = i; j < 6; j++)
		{
			first[i][j] = i + j;
			second[i][j] = -j;
			sum[i][j] = i;
		}
	EXPECT_EQ(first + second, sum);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> first(7), second(12);
	ASSERT_ANY_THROW(first + second);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> first(6), second(6), sub(6);
	for (int i = 0; i < 6; i++)
		for (int j = i; j < 6; j++)
		{
			first[i][j] = i + j;
			second[i][j] = -j;
			sub[i][j] = i + 2 * j;
		}
	EXPECT_EQ(first - second, sub);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> first(6), second(7);
	ASSERT_ANY_THROW(first - second);
}

