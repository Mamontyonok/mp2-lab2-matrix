#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m(5);
    m[0] = v0;
    m[1] = v1;
    m[2] = v2;
    m[3] = v3;
    m[4] = v4;
    TDynamicMatrix<double> m1(m);
    EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m(5);
    m[0] = v0;
    m[1] = v1;
    m[2] = v2;
    m[3] = v3;
    m[4] = v4;
    TDynamicMatrix<double>* p1 = &m;
    TDynamicMatrix<double> m1(m);
    TDynamicMatrix<double>* p2 = &m1;
    EXPECT_NE(p1, p2);
}

TEST(TDynamicMatrix, can_get_size)
{
    TDynamicMatrix<double> m(7);
    EXPECT_EQ(7, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m(5);
    m[0] = v0;
    m[1] = v1;
    m[2] = v2;
    m[3] = v3;
    m[4] = v4;
    EXPECT_EQ(v4, m[4]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m(5);
    m[0] = v0;
    m[1] = v1;
    m[2] = v2;
    m[3] = v3;
    m[4] = v4;
    ASSERT_ANY_THROW(m.at(-3));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m(5);
    m[0] = v0;
    m[1] = v1;
    m[2] = v2;
    m[3] = v3;
    m[4] = v4;
    ASSERT_ANY_THROW(m.at(8));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m(5);
    m[0] = v0;
    m[1] = v1;
    m[2] = v2;
    m[3] = v3;
    m[4] = v4;
    m = m;
    EXPECT_EQ(m, m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m(5);
    m[0] = v0;
    m[1] = v1;
    m[2] = v2;
    m[3] = v3;
    m[4] = v4;
    double *row10 = new double[5] {-3, 1, 0.5, 8, -2.4};
    double *row11 = new double[5] {4, 65, 4123, 1, 0};
    double *row12 = new double[5] {4, 8, 124213, 7, 7};
    double *row13 = new double[5] {21, 2, 22, 13, 0};
    double *row14 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v10(row10, 5);
    TDynamicVector<double> v11(row11, 5);
    TDynamicVector<double> v12(row12, 5);
    TDynamicVector<double> v13(row13, 5);
    TDynamicVector<double> v14(row14, 5);
    delete[] row10;
    delete[] row11;
    delete[] row12;
    delete[] row13;
    delete[] row14;
    TDynamicMatrix<double> m1(5);
    m1[0] = v10;
    m1[1] = v11;
    m1[2] = v12;
    m1[3] = v13;
    m1[4] = v14;
    m = m1;
    EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m(5);
    m[0] = v0;
    m[1] = v1;
    m[2] = v2;
    m[3] = v3;
    m[4] = v4;
    double *row10 = new double[4] {-3, 1, 0.5, 8};
    double *row11 = new double[4] {4, 65, 4123, 1};
    double *row12 = new double[4] {4, 8, 124213, 7};
    double *row13 = new double[4] {21, 2, 22, 13};
    TDynamicVector<double> v10(row10, 4);
    TDynamicVector<double> v11(row11, 4);
    TDynamicVector<double> v12(row12, 4);
    TDynamicVector<double> v13(row13, 4);
    delete[] row10;
    delete[] row11;
    delete[] row12;
    delete[] row13;
    TDynamicMatrix<double> m1(4);
    m1[0] = v10;
    m1[1] = v11;
    m1[2] = v12;
    m1[3] = v13;
    m = m1;
    EXPECT_EQ(m.size(), m1.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m(5);
    m[0] = v0;
    m[1] = v1;
    m[2] = v2;
    m[3] = v3;
    m[4] = v4;
    double *row10 = new double[4] {-3, 1, 0.5, 8};
    double *row11 = new double[4] {4, 65, 4123, 1};
    double *row12 = new double[4] {4, 8, 124213, 7};
    double *row13 = new double[4] {21, 2, 22, 13};
    TDynamicVector<double> v10(row10, 4);
    TDynamicVector<double> v11(row11, 4);
    TDynamicVector<double> v12(row12, 4);
    TDynamicVector<double> v13(row13, 4);
    delete[] row10;
    delete[] row11;
    delete[] row12;
    delete[] row13;
    TDynamicMatrix<double> m1(4);
    m1[0] = v10;
    m1[1] = v11;
    m1[2] = v12;
    m1[3] = v13;
    m = m1;
    EXPECT_EQ(m, m1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m(5);
    m[0] = v0;
    m[1] = v1;
    m[2] = v2;
    m[3] = v3;
    m[4] = v4;
    TDynamicMatrix<double> m1(m);
    bool f = (m1 == m);
    EXPECT_EQ(1, f);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m(5);
    m[0] = v0;
    m[1] = v1;
    m[2] = v2;
    m[3] = v3;
    m[4] = v4;
    bool f = (m == m);
    EXPECT_EQ(1, f);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m(5);
    m[0] = v0;
    m[1] = v1;
    m[2] = v2;
    m[3] = v3;
    m[4] = v4;
    double *row10 = new double[4] {-3, 1, 0.5, 8};
    double *row11 = new double[4] {4, 65, 4123, 1};
    double *row12 = new double[4] {4, 8, 124213, 7};
    double *row13 = new double[4] {21, 2, 22, 13};
    TDynamicVector<double> v10(row10, 4);
    TDynamicVector<double> v11(row11, 4);
    TDynamicVector<double> v12(row12, 4);
    TDynamicVector<double> v13(row13, 4);
    delete[] row10;
    delete[] row11;
    delete[] row12;
    delete[] row13;
    TDynamicMatrix<double> m1(4);
    m1[0] = v10;
    m1[1] = v11;
    m1[2] = v12;
    m1[3] = v13;
    bool f = (m1 == m);
    EXPECT_EQ(0, f);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m1(5);
    m1[0] = v0;
    m1[1] = v1;
    m1[2] = v2;
    m1[3] = v3;
    m1[4] = v4;
    TDynamicMatrix<double> m2(m1);
    TDynamicMatrix<double> m(m1 + m2);
    for (size_t i = 0; i < m2.size(); i++)
        m1[i] = m1[i] + m2[i];
    EXPECT_EQ(m1, m);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m(5);
    m[0] = v0;
    m[1] = v1;
    m[2] = v2;
    m[3] = v3;
    m[4] = v4;
    double *row10 = new double[4] {-3, 1, 0.5, 8};
    double *row11 = new double[4] {4, 65, 4123, 1};
    double *row12 = new double[4] {4, 8, 124213, 7};
    double *row13 = new double[4] {21, 2, 22, 13};
    TDynamicVector<double> v10(row10, 4);
    TDynamicVector<double> v11(row11, 4);
    TDynamicVector<double> v12(row12, 4);
    TDynamicVector<double> v13(row13, 4);
    delete[] row10;
    delete[] row11;
    delete[] row12;
    delete[] row13;
    TDynamicMatrix<double> m1(4);
    m1[0] = v10;
    m1[1] = v11;
    m1[2] = v12;
    m1[3] = v13;
    ASSERT_ANY_THROW(m + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m1(5);
    m1[0] = v0;
    m1[1] = v1;
    m1[2] = v2;
    m1[3] = v3;
    m1[4] = v4;
    TDynamicMatrix<double> m2(m1);
    TDynamicMatrix<double> m(m1 - m2);
    for (size_t i = 0; i < m2.size(); i++)
        m1[i] = m1[i] - m2[i];
    EXPECT_EQ(m1, m);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    double *row0 = new double[5] {3, 1, 0.5, 8, -2.4};
    double *row1 = new double[5] {4, 65, 4123, 1, 0};
    double *row2 = new double[5] {4, 8, 124213, 7, 7};
    double *row3 = new double[5] {21, 2, 22, 13, 0};
    double *row4 = new double[5] {88, 12, -17, 9, 73};
    TDynamicVector<double> v0(row0, 5);
    TDynamicVector<double> v1(row1, 5);
    TDynamicVector<double> v2(row2, 5);
    TDynamicVector<double> v3(row3, 5);
    TDynamicVector<double> v4(row4, 5);
    delete[] row0;
    delete[] row1;
    delete[] row2;
    delete[] row3;
    delete[] row4;
    TDynamicMatrix<double> m(5);
    m[0] = v0;
    m[1] = v1;
    m[2] = v2;
    m[3] = v3;
    m[4] = v4;
    double *row10 = new double[4] {-3, 1, 0.5, 8};
    double *row11 = new double[4] {4, 65, 4123, 1};
    double *row12 = new double[4] {4, 8, 124213, 7};
    double *row13 = new double[4] {21, 2, 22, 13};
    TDynamicVector<double> v10(row10, 4);
    TDynamicVector<double> v11(row11, 4);
    TDynamicVector<double> v12(row12, 4);
    TDynamicVector<double> v13(row13, 4);
    delete[] row10;
    delete[] row11;
    delete[] row12;
    delete[] row13;
    TDynamicMatrix<double> m1(4);
    m1[0] = v10;
    m1[1] = v11;
    m1[2] = v12;
    m1[3] = v13;
    ASSERT_ANY_THROW(m - m1);
}

