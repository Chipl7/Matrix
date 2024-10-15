#include "s21_tests.h"

START_TEST(s21_calc_complements_1) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  s21_create_matrix(1, 1, &matrix_one);
  ck_assert_int_eq(s21_calc_complements(&matrix_one, &matrix_two), S21_OK);
  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  s21_create_matrix(2, 3, &matrix_one);
  ck_assert_int_eq(s21_calc_complements(&matrix_one, &matrix_two),
                   S21_CALC_ERROR);
  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  s21_create_matrix(1, 1, &matrix_one);
  matrix_one.matrix[0][0] = 5;
  ck_assert_int_eq(s21_calc_complements(&matrix_one, &matrix_two), S21_OK);
  ck_assert_double_eq(matrix_two.matrix[0][0], 5);
  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_calc_complements_4) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  s21_create_matrix(2, 2, &matrix_one);
  matrix_one.matrix[0][0] = 1;
  matrix_one.matrix[0][1] = 2;
  matrix_one.matrix[1][0] = 3;
  matrix_one.matrix[1][1] = 4;
  ck_assert_int_eq(s21_calc_complements(&matrix_one, &matrix_two), S21_OK);
  ck_assert_double_eq(matrix_two.matrix[0][0], 4);
  ck_assert_double_eq(matrix_two.matrix[0][1], -3);
  ck_assert_double_eq(matrix_two.matrix[1][0], -2);
  ck_assert_double_eq(matrix_two.matrix[1][1], 1);
  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_calc_complements_5) {
  matrix_t matrix_one;
  matrix_t matrix_two;
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
  ck_assert_int_eq(s21_calc_complements(&matrix_one, &matrix_two), S21_OK);
  ck_assert_double_eq(matrix_two.matrix[0][0], -24);
  ck_assert_double_eq(matrix_two.matrix[0][1], 20);
  ck_assert_double_eq(matrix_two.matrix[0][2], -5);
  ck_assert_double_eq(matrix_two.matrix[1][0], 18);
  ck_assert_double_eq(matrix_two.matrix[1][1], -15);
  ck_assert_double_eq(matrix_two.matrix[1][2], 4);
  ck_assert_double_eq(matrix_two.matrix[2][0], 5);
  ck_assert_double_eq(matrix_two.matrix[2][1], -4);
  ck_assert_double_eq(matrix_two.matrix[2][2], 1);
  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_calc_complements_6) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  s21_create_matrix(4, 4, &matrix_one);
  matrix_one.matrix[0][0] = 1;
  matrix_one.matrix[0][1] = 2;
  matrix_one.matrix[0][2] = 3;
  matrix_one.matrix[0][3] = 4;
  matrix_one.matrix[1][0] = 5;
  matrix_one.matrix[1][1] = 6;
  matrix_one.matrix[1][2] = 7;
  matrix_one.matrix[1][3] = 8;
  matrix_one.matrix[2][0] = 9;
  matrix_one.matrix[2][1] = 10;
  matrix_one.matrix[2][2] = 11;
  matrix_one.matrix[2][3] = 12;
  matrix_one.matrix[3][0] = 13;
  matrix_one.matrix[3][1] = 14;
  matrix_one.matrix[3][2] = 15;
  matrix_one.matrix[3][3] = 16;

  ck_assert_int_eq(s21_calc_complements(&matrix_one, &matrix_two), S21_OK);
  ck_assert_double_eq(matrix_two.matrix[0][0], 0);
  ck_assert_double_eq(matrix_two.matrix[0][1], 0);
  ck_assert_double_eq(matrix_two.matrix[0][2], 0);
  ck_assert_double_eq(matrix_two.matrix[0][3], 0);
  ck_assert_double_eq(matrix_two.matrix[1][0], 0);
  ck_assert_double_eq(matrix_two.matrix[1][1], 0);
  ck_assert_double_eq(matrix_two.matrix[1][2], 0);
  ck_assert_double_eq(matrix_two.matrix[1][3], 0);
  ck_assert_double_eq(matrix_two.matrix[2][0], 0);
  ck_assert_double_eq(matrix_two.matrix[2][1], 0);
  ck_assert_double_eq(matrix_two.matrix[2][2], 0);
  ck_assert_double_eq(matrix_two.matrix[2][3], 0);
  ck_assert_double_eq(matrix_two.matrix[3][0], 0);
  ck_assert_double_eq(matrix_two.matrix[3][1], 0);
  ck_assert_double_eq(matrix_two.matrix[3][2], 0);
  ck_assert_double_eq(matrix_two.matrix[3][3], 0);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_calc_complements_7) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  s21_create_matrix(2, 2, &matrix_one);
  matrix_one.matrix[0][0] = -1;
  matrix_one.matrix[0][1] = -2;
  matrix_one.matrix[1][0] = -3;
  matrix_one.matrix[1][1] = -4;

  ck_assert_int_eq(s21_calc_complements(&matrix_one, &matrix_two), S21_OK);
  ck_assert_double_eq(matrix_two.matrix[0][0], -4);
  ck_assert_double_eq(matrix_two.matrix[0][1], 3);
  ck_assert_double_eq(matrix_two.matrix[1][0], 2);
  ck_assert_double_eq(matrix_two.matrix[1][1], -1);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_calc_complements_8) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  s21_create_matrix(2, 2, &matrix_one);
  matrix_one.matrix[0][0] = 1.5;
  matrix_one.matrix[0][1] = 2.5;
  matrix_one.matrix[1][0] = 3.5;
  matrix_one.matrix[1][1] = 4.5;

  ck_assert_int_eq(s21_calc_complements(&matrix_one, &matrix_two), S21_OK);
  ck_assert_double_eq(matrix_two.matrix[0][0], 4.5);
  ck_assert_double_eq(matrix_two.matrix[0][1], -3.5);
  ck_assert_double_eq(matrix_two.matrix[1][0], -2.5);
  ck_assert_double_eq(matrix_two.matrix[1][1], 1.5);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_calc_complements_9) {
  ck_assert_int_eq(s21_calc_complements(NULL, NULL), S21_ERROR);
}
END_TEST

START_TEST(s21_calc_complements_10) {
  matrix_t result;
  int res = s21_calc_complements(NULL, &result);
  ck_assert_int_eq(res, S21_ERROR);
}
END_TEST

START_TEST(s21_calc_complements_11) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  int res = s21_calc_complements(&A, NULL);
  ck_assert_int_eq(res, S21_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_12) {
  matrix_t A;
  A.matrix = malloc(sizeof(double *) * 2);
  A.matrix[0] = malloc(sizeof(double) * 3);
  A.matrix[1] = malloc(sizeof(double) * 3);
  A.rows = 2;
  A.columns = 3;
  matrix_t result;
  int res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res, S21_CALC_ERROR);
  free(A.matrix[0]);
  free(A.matrix[1]);
  free(A.matrix);
}
END_TEST

START_TEST(s21_calc_complements_13) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  s21_create_matrix(2, 2, &matrix_one);
  matrix_one.matrix[0][0] = 1.0;
  matrix_one.matrix[0][1] = 2.0;
  matrix_one.matrix[1][0] = 3.0;
  matrix_one.matrix[1][1] = 4.0;

  ck_assert_int_eq(s21_calc_complements(&matrix_one, &matrix_two), S21_OK);
  ck_assert_double_eq(matrix_two.matrix[0][0], 4.0);
  ck_assert_double_eq(matrix_two.matrix[0][1], -3.0);
  ck_assert_double_eq(matrix_two.matrix[1][0], -2.0);
  ck_assert_double_eq(matrix_two.matrix[1][1], 1.0);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_calc_complements_14) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  s21_create_matrix(1, 1, &matrix_one);
  matrix_one.matrix[0][0] = 42.0;

  ck_assert_int_eq(s21_calc_complements(&matrix_one, &matrix_two), S21_OK);
  ck_assert_double_eq(matrix_two.matrix[0][0], 42.0);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_calc_complements_15) {
  matrix_t matrix_one;
  matrix_t matrix_two;
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

  ck_assert_int_eq(s21_calc_complements(&matrix_one, &matrix_two), S21_OK);
  ck_assert_double_eq(matrix_two.matrix[0][0], -24.0);
  ck_assert_double_eq(matrix_two.matrix[0][1], 20.0);
  ck_assert_double_eq(matrix_two.matrix[0][2], -5.0);
  ck_assert_double_eq(matrix_two.matrix[1][0], 18.0);
  ck_assert_double_eq(matrix_two.matrix[1][1], -15.0);
  ck_assert_double_eq(matrix_two.matrix[1][2], 4.0);
  ck_assert_double_eq(matrix_two.matrix[2][0], 5.0);
  ck_assert_double_eq(matrix_two.matrix[2][1], -4.0);
  ck_assert_double_eq(matrix_two.matrix[2][2], 1.0);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_calc_complements_16) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  s21_create_matrix(1, 1, &matrix_one);
  matrix_one.matrix[0][0] = 42.0;

  ck_assert_int_eq(s21_calc_complements(&matrix_one, &matrix_two), S21_OK);
  ck_assert_double_eq(matrix_two.matrix[0][0], 42.0);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

Suite *suite_calc_complements(void) {
  Suite *s = suite_create("\033[45m-=test_s21_calc_complements=-\033[0m");
  TCase *tc = tcase_create("test_s21_calc_complements_tc");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, s21_calc_complements_1);
  tcase_add_test(tc, s21_calc_complements_2);
  tcase_add_test(tc, s21_calc_complements_3);
  tcase_add_test(tc, s21_calc_complements_4);
  tcase_add_test(tc, s21_calc_complements_5);
  tcase_add_test(tc, s21_calc_complements_6);
  tcase_add_test(tc, s21_calc_complements_7);
  tcase_add_test(tc, s21_calc_complements_8);
  tcase_add_test(tc, s21_calc_complements_9);
  tcase_add_test(tc, s21_calc_complements_10);
  tcase_add_test(tc, s21_calc_complements_11);
  tcase_add_test(tc, s21_calc_complements_12);
  tcase_add_test(tc, s21_calc_complements_13);
  tcase_add_test(tc, s21_calc_complements_14);
  tcase_add_test(tc, s21_calc_complements_15);
  tcase_add_test(tc, s21_calc_complements_16);

  return s;
}
