#include "s21_tests.h"

START_TEST(s21_mult_matrix_1) {
  matrix_t A, B, result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  B.matrix[0][0] = 7;
  B.matrix[0][1] = 8;
  B.matrix[1][0] = 9;
  B.matrix[1][1] = 10;
  B.matrix[2][0] = 11;
  B.matrix[2][1] = 12;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), S21_OK);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 2);
  ck_assert_int_eq(result.matrix[0][0], 58);
  ck_assert_int_eq(result.matrix[0][1], 64);
  ck_assert_int_eq(result.matrix[1][0], 139);
  ck_assert_int_eq(result.matrix[1][1], 154);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t A, B, result;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), S21_OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t A, B, result;
  s21_create_matrix(2, 6, &A);
  s21_create_matrix(6, 2, &B);

  A.matrix[0][0] = 6;
  A.matrix[0][1] = 7;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 2;

  B.matrix[0][0] = 7;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 9;
  B.matrix[1][1] = 4;
  B.matrix[2][0] = 11;
  B.matrix[2][1] = 2;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), S21_OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  matrix_t A, B, result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(4, 5, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), S21_CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_5) {
  ck_assert_int_eq(s21_mult_matrix(NULL, NULL, NULL), S21_ERROR);
}
END_TEST

START_TEST(s21_mult_matrix_6) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  matrix_t result;

  s21_create_matrix(2, 3, &matrix_one);
  s21_create_matrix(3, 2, &matrix_two);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_one.matrix[i][j] = i + j + 1;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      matrix_two.matrix[i][j] = i * j + 1;
    }
  }

  ck_assert_int_eq(s21_mult_matrix(&matrix_one, &matrix_two, &result), S21_OK);

  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 2);
  ck_assert_double_eq(result.matrix[0][0], 6);
  ck_assert_double_eq(result.matrix[0][1], 14);
  ck_assert_double_eq(result.matrix[1][0], 9);
  ck_assert_double_eq(result.matrix[1][1], 20);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_7) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  matrix_t result;

  s21_create_matrix(2, 3, &matrix_one);
  s21_create_matrix(4, 2, &matrix_two);

  ck_assert_int_eq(s21_mult_matrix(&matrix_one, &matrix_two, &result),
                   S21_CALC_ERROR);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_mult_matrix_8) {
  matrix_t matrix_one;
  matrix_t result;

  s21_create_matrix(3, 3, &matrix_one);

  ck_assert_int_eq(s21_mult_matrix(&matrix_one, NULL, &result), S21_ERROR);

  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_mult_matrix_9) {
  matrix_t matrix_one;
  matrix_t matrix_two;

  s21_create_matrix(3, 3, &matrix_one);
  s21_create_matrix(3, 3, &matrix_two);

  ck_assert_int_eq(s21_mult_matrix(&matrix_one, &matrix_two, NULL), S21_ERROR);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_mult_matrix_10) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  matrix_t result;

  s21_create_matrix(1, 1, &matrix_one);
  s21_create_matrix(1, 1, &matrix_two);

  ck_assert_int_eq(s21_mult_matrix(&matrix_one, &matrix_two, &result), S21_OK);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_11) {
  matrix_t matrix_one;
  matrix_t result;

  s21_create_matrix(3, 3, &matrix_one);

  ck_assert_int_eq(s21_mult_matrix(NULL, &matrix_one, &result), S21_ERROR);

  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_mult_matrix_12) {
  ck_assert_int_eq(s21_mult_matrix(NULL, NULL, NULL), S21_ERROR);
}
END_TEST

Suite *suite_mult_matrix(void) {
  Suite *s = suite_create("\033[45m-=test_s21_mult_matrix=-\033[0m");
  TCase *tc = tcase_create("test_s21_mult_matrix_tc");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, s21_mult_matrix_1);
  tcase_add_test(tc, s21_mult_matrix_2);
  tcase_add_test(tc, s21_mult_matrix_3);
  tcase_add_test(tc, s21_mult_matrix_4);
  tcase_add_test(tc, s21_mult_matrix_5);
  tcase_add_test(tc, s21_mult_matrix_6);
  tcase_add_test(tc, s21_mult_matrix_7);
  tcase_add_test(tc, s21_mult_matrix_8);
  tcase_add_test(tc, s21_mult_matrix_9);
  tcase_add_test(tc, s21_mult_matrix_10);
  tcase_add_test(tc, s21_mult_matrix_11);
  tcase_add_test(tc, s21_mult_matrix_12);

  return s;
}