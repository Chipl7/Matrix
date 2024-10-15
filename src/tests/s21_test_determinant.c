#include "s21_tests.h"

START_TEST(s21_determinant_1) {
  matrix_t matrix_one;
  double result;
  s21_create_matrix(1, 1, &matrix_one);
  ck_assert_int_eq(s21_determinant(&matrix_one, &result), S21_OK);
  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t matrix_one;
  double result;
  s21_create_matrix(2, 3, &matrix_one);
  ck_assert_int_eq(s21_determinant(&matrix_one, &result), S21_CALC_ERROR);
  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_determinant_3) {
  matrix_t matrix_one;
  double result;
  s21_create_matrix(1, 1, &matrix_one);
  matrix_one.matrix[0][0] = 5;
  ck_assert_int_eq(s21_determinant(&matrix_one, &result), S21_OK);
  ck_assert_double_eq(result, 5);
  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_determinant_4) {
  matrix_t matrix_one;
  double result;
  s21_create_matrix(2, 2, &matrix_one);
  matrix_one.matrix[0][0] = 1;
  matrix_one.matrix[0][1] = 2;
  matrix_one.matrix[1][0] = 3;
  matrix_one.matrix[1][1] = 4;
  ck_assert_int_eq(s21_determinant(&matrix_one, &result), S21_OK);
  ck_assert_double_eq(result, -2);
  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_determinant_5) {
  matrix_t matrix_one;
  double result;
  s21_create_matrix(3, 3, &matrix_one);
  matrix_one.matrix[0][0] = 1;
  matrix_one.matrix[0][1] = 2;
  matrix_one.matrix[0][2] = 3;
  matrix_one.matrix[1][0] = 0;
  matrix_one.matrix[1][1] = 1;
  matrix_one.matrix[1][2] = 4;
  matrix_one.matrix[2][0] = 5;
  matrix_one.matrix[2][1] = 6;
  matrix_one.matrix[2][2] = 0;
  ck_assert_int_eq(s21_determinant(&matrix_one, &result), S21_OK);
  ck_assert_double_eq(result, 1);
  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_determinant_6) {
  ck_assert_int_eq(s21_determinant(NULL, NULL), S21_ERROR);
}
END_TEST

START_TEST(s21_determinant_7) {
  double result;
  int res = s21_determinant(NULL, &result);
  ck_assert_int_eq(res, S21_ERROR);
}
END_TEST

START_TEST(s21_determinant_8) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  int res = s21_determinant(&A, NULL);
  ck_assert_int_eq(res, S21_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_9) {
  matrix_t A;
  A.rows = 2;
  A.columns = 3;
  A.matrix = malloc(sizeof(double *) * A.rows);
  for (int i = 0; i < A.rows; i++) {
    A.matrix[i] = malloc(sizeof(double) * A.columns);
  }
  double result;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, S21_CALC_ERROR);
  for (int i = 0; i < A.rows; i++) {
    free(A.matrix[i]);
  }
  free(A.matrix);
}
END_TEST

START_TEST(s21_determinant_10) {
  matrix_t matrix_one;
  s21_create_matrix(2, 2, &matrix_one);
  matrix_one.matrix[0][0] = 1.0;
  matrix_one.matrix[0][1] = 2.0;
  matrix_one.matrix[1][0] = 3.0;
  matrix_one.matrix[1][1] = 4.0;
  double result;

  ck_assert_int_eq(s21_determinant(&matrix_one, &result), S21_OK);
  ck_assert_double_eq(result, -2.0);

  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_determinant_11) {
  matrix_t matrix_one;
  s21_create_matrix(3, 3, &matrix_one);
  matrix_one.matrix[0][0] = 1.0;
  matrix_one.matrix[0][1] = 2.0;
  matrix_one.matrix[0][2] = 3.0;
  matrix_one.matrix[1][0] = 0.0;
  matrix_one.matrix[1][1] = 1.0;
  matrix_one.matrix[1][2] = 4.0;
  matrix_one.matrix[2][0] = 5.0;
  matrix_one.matrix[2][1] = 6.0;
  matrix_one.matrix[2][2] = 0.0;
  double result;

  ck_assert_int_eq(s21_determinant(&matrix_one, &result), S21_OK);
  ck_assert_double_eq(result, 1.0);

  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_determinant_12) {
  matrix_t matrix_one;
  s21_create_matrix(1, 1, &matrix_one);
  matrix_one.matrix[0][0] = 42.0;
  double result;

  ck_assert_int_eq(s21_determinant(&matrix_one, &result), S21_OK);
  ck_assert_double_eq(result, 42.0);

  s21_remove_matrix(&matrix_one);
}
END_TEST

Suite *suite_determinant(void) {
  Suite *s = suite_create("\033[45m-=test_s21_determinant=-\033[0m");
  TCase *tc = tcase_create("test_s21_determinant_tc");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, s21_determinant_1);
  tcase_add_test(tc, s21_determinant_2);
  tcase_add_test(tc, s21_determinant_3);
  tcase_add_test(tc, s21_determinant_4);
  tcase_add_test(tc, s21_determinant_5);
  tcase_add_test(tc, s21_determinant_6);
  tcase_add_test(tc, s21_determinant_7);
  tcase_add_test(tc, s21_determinant_8);
  tcase_add_test(tc, s21_determinant_9);
  tcase_add_test(tc, s21_determinant_10);
  tcase_add_test(tc, s21_determinant_11);
  tcase_add_test(tc, s21_determinant_12);

  return s;
}
