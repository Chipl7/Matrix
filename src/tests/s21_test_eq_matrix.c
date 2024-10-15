#include "s21_tests.h"

START_TEST(s21_eq_matrix_1) {
  matrix_t A, B;
  int response = 1;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1;
      B.matrix[i][j] = 1;
    }
  }

  response = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(response, 1);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t A, B;
  int response = S21_SUCCESS;
  double item = 0.1234567;

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = item;
      B.matrix[i][j] = item;
    }
  }

  response = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(response, 1);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  matrix_t A, B;
  int response = S21_SUCCESS;
  double item = 0.1234567;
  double item1 = 0.1234568;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = item;
      B.matrix[i][j] = item1;
    }
  }

  response = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(response, 0);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  matrix_t A, B;
  int response = S21_SUCCESS;
  double item = 0.1234567;
  double item1 = 0.12345678;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = item;
      B.matrix[i][j] = item1;
    }
  }

  response = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(response, 1);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  matrix_t A, B;
  int response = S21_SUCCESS;
  double item = 0.1234567;
  double item1 = 0.12345678;

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 3, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = item;
    }
  }

  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = item1;
    }
  }

  response = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(response, 0);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  matrix_t A, B;
  int response;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1.0;
      B.matrix[i][j] = 1.0;
    }
  }

  response = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(response, S21_SUCCESS);
}
END_TEST

START_TEST(s21_eq_matrix_7) {
  matrix_t A, B;
  int response;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 3, &B);

  response = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(response, S21_FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_8) {
  matrix_t A, B;
  int response;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.1;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;

  response = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(response, S21_FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_9) {
  matrix_t A, B;
  int response;

  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;

  s21_create_matrix(2, 2, &B);

  response = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&B);

  ck_assert_int_eq(response, S21_FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_10) {
  matrix_t A, B;
  int response;
  A.rows = -1;
  A.columns = -1;
  A.matrix = NULL;

  s21_create_matrix(2, 2, &B);

  response = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&B);

  ck_assert_int_eq(response, S21_FAILURE);
}
END_TEST

Suite *suite_eq_matrix(void) {
  Suite *s = suite_create("\033[45m-=test_s21_eq_matrix=-\033[0m");
  TCase *tc = tcase_create("test_s21_eq_matrix_tc");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, s21_eq_matrix_1);
  tcase_add_test(tc, s21_eq_matrix_2);
  tcase_add_test(tc, s21_eq_matrix_3);
  tcase_add_test(tc, s21_eq_matrix_4);
  tcase_add_test(tc, s21_eq_matrix_5);
  tcase_add_test(tc, s21_eq_matrix_6);
  tcase_add_test(tc, s21_eq_matrix_7);
  tcase_add_test(tc, s21_eq_matrix_8);
  tcase_add_test(tc, s21_eq_matrix_9);
  tcase_add_test(tc, s21_eq_matrix_10);

  return s;
}