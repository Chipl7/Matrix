#include "s21_tests.h"

START_TEST(s21_sub_matrix_1) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 5;
  A.matrix[0][1] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 2;

  B.matrix[0][0] = 2;
  B.matrix[0][1] = 1;
  B.matrix[1][0] = 1;
  B.matrix[1][1] = 0;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), S21_OK);
  ck_assert_int_eq(result.matrix[0][0], 3);
  ck_assert_int_eq(result.matrix[0][1], 2);
  ck_assert_int_eq(result.matrix[1][0], 3);
  ck_assert_int_eq(result.matrix[1][1], 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 10;
  A.matrix[0][1] = 20;
  A.matrix[0][2] = 30;
  A.matrix[1][0] = 40;
  A.matrix[1][1] = 50;
  A.matrix[1][2] = 60;
  A.matrix[2][0] = 70;
  A.matrix[2][1] = 80;
  A.matrix[2][2] = 90;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), S21_OK);
  ck_assert_int_eq(result.matrix[0][0], 9);
  ck_assert_int_eq(result.matrix[0][1], 18);
  ck_assert_int_eq(result.matrix[0][2], 27);
  ck_assert_int_eq(result.matrix[1][0], 36);
  ck_assert_int_eq(result.matrix[1][1], 45);
  ck_assert_int_eq(result.matrix[1][2], 54);
  ck_assert_int_eq(result.matrix[2][0], 63);
  ck_assert_int_eq(result.matrix[2][1], 72);
  ck_assert_int_eq(result.matrix[2][2], 81);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 3, &B);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), S21_CALC_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_4) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), S21_OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_5) {
  matrix_t A, result;

  ck_assert_int_eq(s21_sub_matrix(NULL, NULL, &result), S21_ERROR);

  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_sub_matrix(&A, NULL, &result), S21_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_sub_matrix_6) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  matrix_t matrix_three;
  s21_create_matrix(3, 3, &matrix_one);
  s21_create_matrix(3, 3, &matrix_two);
  ck_assert_int_eq(s21_sub_matrix(&matrix_one, &matrix_two, &matrix_three), 0);
  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
  s21_remove_matrix(&matrix_three);
}
END_TEST

START_TEST(s21_sub_matrix_7) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  matrix_t matrix_three;
  s21_create_matrix(3, 3, &matrix_one);
  s21_create_matrix(2, 2, &matrix_two);
  ck_assert_int_eq(s21_sub_matrix(&matrix_one, &matrix_two, &matrix_three), 2);
  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_sub_matrix_8) {
  matrix_t matrix_one;
  s21_create_matrix(3, 3, &matrix_one);
  ck_assert_int_eq(s21_sub_matrix(&matrix_one, NULL, NULL), 1);
  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_sub_matrix_9) {
  matrix_t matrix_one;
  s21_create_matrix(3, 3, &matrix_one);
  ck_assert_int_eq(s21_sub_matrix(NULL, &matrix_one, NULL), 1);
  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_sub_matrix_10) {
  matrix_t matrix_one;
  s21_create_matrix(3, 3, &matrix_one);
  ck_assert_int_eq(s21_sub_matrix(NULL, NULL, &matrix_one), 1);
  s21_remove_matrix(&matrix_one);
}
END_TEST

Suite *suite_sub_matrix(void) {
  Suite *s = suite_create("\033[45m-=test_s21_sub_matrix=-\033[0m");
  TCase *tc = tcase_create("test_s21_sub_matrix_tc");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, s21_sub_matrix_1);
  tcase_add_test(tc, s21_sub_matrix_2);
  tcase_add_test(tc, s21_sub_matrix_3);
  tcase_add_test(tc, s21_sub_matrix_4);
  tcase_add_test(tc, s21_sub_matrix_5);
  tcase_add_test(tc, s21_sub_matrix_6);
  tcase_add_test(tc, s21_sub_matrix_7);
  tcase_add_test(tc, s21_sub_matrix_8);
  tcase_add_test(tc, s21_sub_matrix_9);
  tcase_add_test(tc, s21_sub_matrix_10);

  return s;
}