#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  code_error code = S21_OK;
  if (s21_is_uncorrect_matrix(A) || s21_is_uncorrect_matrix(B)) {
    return S21_ERROR;
  }
  if (!s21_eq_rows_columns(A, B)) {
    return S21_CALC_ERROR;
  }
  if (code == S21_OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return code;
}