#include "s21_tests.h"

START_TEST(s21_remove_matrix_1) {
  matrix_t matrix;
  s21_create_matrix(3, 3, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_eq(matrix.matrix, NULL);
}
END_TEST

START_TEST(s21_remove_matrix_2) {
  matrix_t *A = NULL;
  s21_remove_matrix(A);
}
END_TEST

START_TEST(s21_remove_matrix_3) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 42.0;

  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(s21_remove_matrix_4) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(s21_remove_matrix_5) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;

  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

Suite *suite_remove_matrix(void) {
  Suite *s = suite_create("\033[45m-=test_s21_remove_matrix=-\033[0m");
  TCase *tc = tcase_create("test_s21_remove_matrix_tc");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, s21_remove_matrix_1);
  tcase_add_test(tc, s21_remove_matrix_2);
  tcase_add_test(tc, s21_remove_matrix_3);
  tcase_add_test(tc, s21_remove_matrix_4);
  tcase_add_test(tc, s21_remove_matrix_5);

  return s;
}