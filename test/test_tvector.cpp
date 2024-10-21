#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    delete[] a;
    TDynamicVector<double> v2(v1);
    EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    delete[] a;
    TDynamicVector<double> v2(v1);
    TDynamicVector<double>* p1 = &v1;
    TDynamicVector<double>* p2 = &v2;
    EXPECT_NE(p1, p2);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
    TDynamicVector<int> v(10);
    ASSERT_ANY_THROW(v.at(-8) = 3);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
    TDynamicVector<int> v(10);
    ASSERT_ANY_THROW(v.at(11) = 3);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    delete[] a;
    v1 = v1;
    EXPECT_EQ(v1, v1); //
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    delete[] a;
    double *b = new double[10];
    for (int i = 0; i < 10; i++)
        b[i] = 3 + i;
    TDynamicVector<double> v2(b, 10);
    delete[] b;
    v1 = v2;
    EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    delete[] a;
    double *b = new double[15];
    for (int i = 0; i < 15; i++)
        b[i] = 3 + i;
    TDynamicVector<double> v2(b, 15);
    delete[] b;
    v1 = v2;
    EXPECT_EQ(v1.size(), v2.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    delete[] a;
    double *b = new double[15];
    for (int i = 0; i < 15; i++)
        b[i] = 3 + i;
    TDynamicVector<double> v2(b, 15);
    delete[] b;
    v1 = v2;
    EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    TDynamicVector<double> v2(a, 10);
    delete[] a;
    EXPECT_EQ(v1, v2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    delete[] a;
    bool f = (v1 == v1);
    EXPECT_EQ(1, f);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
    double *a = new double[10]();
    TDynamicVector<double> v1(a, 10);
    delete[] a;
    double *b = new double[11]();
    TDynamicVector<double> v2(b, 11);
    delete[] b;
    bool f = (v1 == v2);
    EXPECT_EQ(0, f);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    TDynamicVector<double> v2(a, 10);
    delete[] a;
    double skal = 5.5;
    v1 = v1 + skal;
    for (int i = 0; i < 10; i++)
        v2[i] += 5.5;
    bool f = (v1 == v2);
    EXPECT_EQ(1, f);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    TDynamicVector<double> v2(a, 10);
    delete[] a;
    double skal = 5.5;
    v1 = v1 - skal;
    for (int i = 0; i < 10; i++)
        v2[i] -= 5.5;
    bool f = (v1 == v2);
    EXPECT_EQ(1, f);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    TDynamicVector<double> v2(a, 10);
    delete[] a;
    double skal = 5.5;
    v1 = v1 * skal;
    for (int i = 0; i < 10; i++)
        v2[i] *= 5.5;
    bool f = (v1 == v2);
    EXPECT_EQ(1, f);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    delete[] a;
    double *b = new double[10];
    for (int i = 0; i < 10; i++)
        b[i] = 3 + i;
    TDynamicVector<double> v2(b, 10);
    delete[] b;
    TDynamicVector<double> v = v1 + v2;
    for (int i = 0; i < 10; i++)
        v2[i] += i;
    EXPECT_EQ(v, v2);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    delete[] a;
    double *b = new double[15] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    for (int i = 0; i < 15; i++)
        b[i] = 3 + i;
    TDynamicVector<double> v2(b, 15);
    delete[] b;
    ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    delete[] a;
    double *b = new double[10];
    for (int i = 0; i < 10; i++)
        b[i] = 3 + i;
    TDynamicVector<double> v2(b, 10);
    delete[] b;
    TDynamicVector<double> v = v2 - v1;
    for (int i = 0; i < 10; i++)
        v2[i] -= i;
    EXPECT_EQ(v, v2);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    delete[] a;
    double *b = new double[10];
    for (int i = 0; i < 15; i++)
        b[i] = 3 + i;
    TDynamicVector<double> v2(b, 15);
    delete[] b;
    ASSERT_ANY_THROW(v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    delete[] a;
    double *b = new double[10];
    for (int i = 0; i < 10; i++)
        b[i] = 3 + i;
    TDynamicVector<double> v2(b, 10);
    delete[] b;
    double tmp1 = v1 * v2, tmp2 = 0;
    for (int i = 0; i < 10; i++)
        tmp2 += v1[i] * v2[i];
    EXPECT_EQ(tmp1, tmp2);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
    double *a = new double[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TDynamicVector<double> v1(a, 10);
    delete[] a;
    double *b = new double[15];
    for (int i = 0; i < 15; i++)
        b[i] = 3 + i;
    TDynamicVector<double> v2(b, 15);
    delete[] b;
    ASSERT_ANY_THROW(v1 * v2);
}

