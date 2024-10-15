#include "s21_tests.h"

START_TEST(s21_create_matrix_1) {
  matrix_t matrix;
  ck_assert_int_eq(s21_create_matrix(3, 3, &matrix), S21_OK);
  ck_assert_int_eq(matrix.rows, 3);
  ck_assert_int_eq(matrix.columns, 3);
  ck_assert_ptr_ne(matrix.matrix, NULL);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  matrix_t matrix;
  ck_assert_int_eq(s21_create_matrix(1, 1, &matrix), S21_OK);
  ck_assert_int_eq(matrix.rows, 1);
  ck_assert_int_eq(matrix.columns, 1);
  ck_assert_ptr_ne(matrix.matrix, NULL);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t matrix;
  ck_assert_int_eq(s21_create_matrix(10000, 10000, &matrix), S21_OK);
  ck_assert_int_eq(matrix.rows, 10000);
  ck_assert_int_eq(matrix.columns, 10000);
  ck_assert_ptr_ne(matrix.matrix, NULL);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  matrix_t matrix;
  ck_assert_int_eq(s21_create_matrix(0, 0, &matrix), S21_ERROR);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  matrix_t matrix;
  ck_assert_int_eq(s21_create_matrix(0, 3, &matrix), S21_ERROR);
}
END_TEST

START_TEST(s21_create_matrix_6) {
  matrix_t matrix;
  ck_assert_int_eq(s21_create_matrix(3, 0, &matrix), S21_ERROR);
}
END_TEST

START_TEST(s21_create_matrix_7) {
  matrix_t matrix;
  ck_assert_int_eq(s21_create_matrix(-3, 3, &matrix), S21_ERROR);
}
END_TEST

START_TEST(s21_create_matrix_8) {
  matrix_t matrix;
  ck_assert_int_eq(s21_create_matrix(3, -3, &matrix), S21_ERROR);
}
END_TEST

START_TEST(s21_create_matrix_9) {
  matrix_t matrix;
  ck_assert_int_eq(s21_create_matrix(-3, -3, &matrix), S21_ERROR);
}
END_TEST

START_TEST(s21_create_matrix_10) {
  ck_assert_int_eq(s21_create_matrix(3, 3, NULL), S21_ERROR);
}
END_TEST

Suite *suite_create_matrix(void) {
  Suite *s = suite_create("\033[45m-=test_s21_create_matrix=-\033[0m");
  TCase *tc = tcase_create("test_s21_create_matrix_tc");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, s21_create_matrix_1);
  tcase_add_test(tc, s21_create_matrix_2);
  tcase_add_test(tc, s21_create_matrix_3);
  tcase_add_test(tc, s21_create_matrix_4);
  tcase_add_test(tc, s21_create_matrix_5);
  tcase_add_test(tc, s21_create_matrix_6);
  tcase_add_test(tc, s21_create_matrix_7);
  tcase_add_test(tc, s21_create_matrix_8);
  tcase_add_test(tc, s21_create_matrix_9);
  tcase_add_test(tc, s21_create_matrix_10);

  return s;
}
