#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (s21_is_uncorrect_matrix(A) || result == NULL) {
    return S21_ERROR;
  }
  s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->columns; i++) {
    for (int j = 0; j < A->rows; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }
  return S21_OK;
}