#include "s21_tests.h"

START_TEST(s21_sum_matrix_1) {
  ck_assert_int_eq(s21_sum_matrix(NULL, NULL, NULL), 1);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  matrix_t matrix_three;
  s21_create_matrix(3, 3, &matrix_one);
  s21_create_matrix(3, 3, &matrix_two);
  ck_assert_int_eq(s21_sum_matrix(&matrix_one, &matrix_two, &matrix_three), 0);
  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
  s21_remove_matrix(&matrix_three);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  matrix_t matrix_three;
  s21_create_matrix(3, 3, &matrix_one);
  s21_create_matrix(2, 2, &matrix_two);
  ck_assert_int_eq(s21_sum_matrix(&matrix_one, &matrix_two, &matrix_three), 2);
  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_sum_matrix_4) {
  matrix_t matrix_one;
  s21_create_matrix(3, 3, &matrix_one);
  ck_assert_int_eq(s21_sum_matrix(&matrix_one, NULL, NULL), 1);
  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_sum_matrix_5) {
  matrix_t matrix_one;
  s21_create_matrix(3, 3, &matrix_one);
  ck_assert_int_eq(s21_sum_matrix(NULL, &matrix_one, NULL), 1);
  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_sum_matrix_6) {
  matrix_t matrix_one;
  s21_create_matrix(3, 3, &matrix_one);
  ck_assert_int_eq(s21_sum_matrix(NULL, NULL, &matrix_one), 1);
  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_sum_matrix_7) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  matrix_t matrix_three;
  s21_create_matrix(3, 3, &matrix_one);
  s21_create_matrix(3, 3, &matrix_two);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_one.matrix[i][j] = i + j;
      matrix_two.matrix[i][j] = i * j;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&matrix_one, &matrix_two, &matrix_three),
                   S21_OK);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(matrix_three.matrix[i][j], (i + j) + (i * j));
    }
  }

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
  s21_remove_matrix(&matrix_three);
}
END_TEST

START_TEST(s21_sum_matrix_8) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  matrix_t matrix_three;

  s21_create_matrix(2, 3, &matrix_one);
  s21_create_matrix(3, 2, &matrix_two);

  ck_assert_int_eq(s21_sum_matrix(&matrix_one, &matrix_two, &matrix_three),
                   S21_CALC_ERROR);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
}
END_TEST

START_TEST(s21_sum_matrix_9) {
  matrix_t matrix_one;
  matrix_t matrix_three;

  s21_create_matrix(3, 3, &matrix_one);

  ck_assert_int_eq(s21_sum_matrix(&matrix_one, NULL, &matrix_three), S21_ERROR);

  s21_remove_matrix(&matrix_one);
}
END_TEST

START_TEST(s21_sum_matrix_10) {
  matrix_t matrix_one;
  matrix_t matrix_two;
  matrix_t matrix_three;

  s21_create_matrix(1, 1, &matrix_one);
  s21_create_matrix(1, 1, &matrix_two);

  ck_assert_int_eq(s21_sum_matrix(&matrix_one, &matrix_two, &matrix_three),
                   S21_OK);

  ck_assert_int_eq(matrix_three.rows, 1);
  ck_assert_int_eq(matrix_three.columns, 1);

  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&matrix_two);
  s21_remove_matrix(&matrix_three);
}
END_TEST

Suite *suite_sum_matrix(void) {
  Suite *s = suite_create("\033[45m-=test_s21_sum_matrix=-\033[0m");
  TCase *tc = tcase_create("test_s21_sum_matrix_tc");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, s21_sum_matrix_1);
  tcase_add_test(tc, s21_sum_matrix_2);
  tcase_add_test(tc, s21_sum_matrix_3);
  tcase_add_test(tc, s21_sum_matrix_4);
  tcase_add_test(tc, s21_sum_matrix_5);
  tcase_add_test(tc, s21_sum_matrix_6);
  tcase_add_test(tc, s21_sum_matrix_7);
  tcase_add_test(tc, s21_sum_matrix_8);
  tcase_add_test(tc, s21_sum_matrix_9);
  tcase_add_test(tc, s21_sum_matrix_10);

  return s;
}