#include "s21_tests.h"

START_TEST(s21_transpose_1) { ck_assert_int_eq(s21_transpose(NULL, NULL), 1); }
END_TEST

START_TEST(s21_transpose_2) {
  matrix_t matrix_one;
  matrix_t result;
  s21_create_matrix(3, 3, &matrix_one);
  ck_assert_int_eq(s21_transpose(&matrix_one, &result), S21_OK);
  s21_remove_matrix(&matrix_one);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_3) {
  matrix_t A, result, reference;
  int response = 0;

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &reference);
  double n[3][2] = {{1.0, 4.0}, {2.0, 5.0}, {3.0, 6.0}};
  double r[2][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = n[i][j];
    }
  }

  for (int i = 0; i < reference.rows; i++) {
    for (int j = 0; j < reference.columns; j++) {
      reference.matrix[i][j] = r[i][j];
    }
  }

  response = s21_transpose(&A, &result);

  ck_assert_int_eq(response, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&reference);
}
END_TEST

START_TEST(s21_transpose_4) {
  matrix_t A;
  int response = 0;

  s21_create_matrix(2, 2, &A);

  response = s21_transpose(&A, NULL);

  ck_assert_int_eq(response, S21_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_5) {
  matrix_t A, result, reference;
  int response = 0;

  s21_create_matrix(5, 2, &A);
  s21_create_matrix(2, 5, &reference);

  double n[5][2] = {{1.0, 4.0}, {2.0, 5.0}, {3.0, 6.0}, {2.0, 5.0}, {3.0, 6.0}};
  double r[2][5] = {{1.0, 2.0, 3.0, 2.0, 3.0}, {4.0, 5.0, 6.0, 5.0, 6.0}};

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = n[i][j];
    }
  }

  for (int i = 0; i < reference.rows; i++) {
    for (int j = 0; j < reference.columns; j++) {
      reference.matrix[i][j] = r[i][j];
    }
  }

  response = s21_transpose(&A, &result);

  ck_assert_int_eq(response, S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&reference);
}
END_TEST

START_TEST(s21_transpose_6) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 10;
  A.matrix[0][1] = 20;
  A.matrix[0][2] = 30;
  A.matrix[1][0] = 40;
  A.matrix[1][1] = 50;
  A.matrix[1][2] = 60;
  A.matrix[2][0] = 70;
  A.matrix[2][1] = 80;
  A.matrix[2][2] = 90;

  ck_assert_int_eq(s21_transpose(&A, &result), S21_OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_7) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 10;
  A.matrix[0][1] = 20;
  A.matrix[0][2] = 30;
  A.matrix[1][0] = 40;
  A.matrix[1][1] = 50;
  A.matrix[1][2] = 60;
  A.matrix[2][0] = 70;
  A.matrix[2][1] = 80;
  A.matrix[2][2] = 90;

  ck_assert_int_eq(s21_transpose(&A, &result), S21_OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_8) {
  ck_assert_int_eq(s21_transpose(NULL, NULL), S21_ERROR);
}
END_TEST

START_TEST(s21_transpose_9) {
  matrix_t A, result;
  s21_create_matrix(1, 1, &A);

  A.matrix[0][0] = 10;

  ck_assert_int_eq(s21_transpose(&A, &result), S21_OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_10) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 10;
  A.matrix[0][1] = 20;
  A.matrix[1][0] = 30;
  A.matrix[1][1] = 40;

  ck_assert_int_eq(s21_transpose(&A, &result), S21_OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_11) {
  matrix_t A;
  int x = s21_create_matrix(0, 0, &A);

  ck_assert_int_eq(x, S21_ERROR);
}
END_TEST

Suite *suite_transpose(void) {
  Suite *s = suite_create("\033[45m-=test_s21_transpose=-\033[0m");
  TCase *tc = tcase_create("test_s21_transpose_tc");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, s21_transpose_1);
  tcase_add_test(tc, s21_transpose_2);
  tcase_add_test(tc, s21_transpose_3);
  tcase_add_test(tc, s21_transpose_4);
  tcase_add_test(tc, s21_transpose_5);
  tcase_add_test(tc, s21_transpose_6);
  tcase_add_test(tc, s21_transpose_7);
  tcase_add_test(tc, s21_transpose_8);
  tcase_add_test(tc, s21_transpose_9);
  tcase_add_test(tc, s21_transpose_10);
  tcase_add_test(tc, s21_transpose_11);

  return s;
}