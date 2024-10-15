#include "s21_tests.h"

START_TEST(s21_mult_number_1) {
  matrix_t A, result, reference;
  int response = 0;
  int n = 5;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &reference);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1;
      reference.matrix[i][j] = 5;
    }
  }

  response = s21_mult_number(&A, n, &result);

  ck_assert_int_eq(response, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&reference);
}
END_TEST

START_TEST(s21_mult_number_2) {
  matrix_t A, result, reference;
  int response = 0;
  double n = 5.98374265765;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &reference);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
      reference.matrix[i][j] = i * n;
    }
  }

  response = s21_mult_number(&A, n, &result);

  ck_assert_int_eq(response, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&reference);
}
END_TEST

START_TEST(s21_mult_number_3) {
  matrix_t A;
  int response = 0;
  double n = 5.98374265;

  s21_create_matrix(3, 3, &A);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
    }
  }

  response = s21_mult_number(&A, n, NULL);

  ck_assert_int_eq(response, S21_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_4) {
  matrix_t A, result, reference;
  int response = 0;
  int n = 0;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &reference);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
    }
  }

  response = s21_mult_number(&A, n, &result);

  ck_assert_int_eq(response, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&reference);
}
END_TEST

START_TEST(s21_mult_number_5) {
  matrix_t matrix_one;
  matrix_t result;
  double number = 2.0;

  s21_create_matrix(3, 3, &matrix_one);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_one.matrix[i][j] = i + j + 1;
    }
  }

  ck_assert_int_eq(s21_mult_number(&matrix_one, number, &result), S21_OK);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(result.matrix[i][j], (i + j + 1) * number);
    }
  }

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_6) {
  matrix_t matrix_one;
  matrix_t result;
  double number = 2.0;

  s21_create_matrix(3, 3, &matrix_one);

  ck_assert_int_eq(s21_mult_number(&matrix_one, number, &result), S21_OK);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_7) {
  matrix_t matrix_one;
  double number = 2.0;

  s21_create_matrix(3, 3, &matrix_one);

  ck_assert_int_eq(s21_mult_number(&matrix_one, number, NULL), S21_ERROR);

  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_mult_number_8) {
  matrix_t matrix_one;
  matrix_t result;
  double number = 2.0;

  s21_create_matrix(1, 1, &matrix_one);

  ck_assert_int_eq(s21_mult_number(&matrix_one, number, &result), S21_OK);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&result);
}
END_TEST

Suite *suite_mult_number(void) {
  Suite *s = suite_create("\033[45m-=test_s21_mult_number=-\033[0m");
  TCase *tc = tcase_create("test_s21_mult_number_tc");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, s21_mult_number_1);
  tcase_add_test(tc, s21_mult_number_2);
  tcase_add_test(tc, s21_mult_number_3);
  tcase_add_test(tc, s21_mult_number_4);
  tcase_add_test(tc, s21_mult_number_5);
  tcase_add_test(tc, s21_mult_number_6);
  tcase_add_test(tc, s21_mult_number_7);
  tcase_add_test(tc, s21_mult_number_8);

  return s;
}