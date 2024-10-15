#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  code_error code = S21_SUCCESS;
  if (s21_is_uncorrect_matrix(A) || s21_is_uncorrect_matrix(B) ||
      !s21_eq_rows_columns(A, B)) {
    return S21_FAILURE;
  }
  if (code == S21_SUCCESS) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          code = S21_FAILURE;
        }
      }
    }
  }
  return code;
}