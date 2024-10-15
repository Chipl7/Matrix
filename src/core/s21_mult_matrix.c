#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  code_error code = S21_OK;
  if (s21_is_uncorrect_matrix(A) || s21_is_uncorrect_matrix(B) ||
      result == NULL) {
    return S21_ERROR;
  }
  if (A->columns != B->rows) {
    return S21_CALC_ERROR;
  }
  s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      double sum = 0;
      for (int k = 0; k < A->columns; k++) {
        sum += A->matrix[i][k] * B->matrix[k][j];
      }
      result->matrix[i][j] = sum;
    }
  }
  return code;
}