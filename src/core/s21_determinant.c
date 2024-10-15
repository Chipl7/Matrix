#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  code_error code = S21_OK;
  if (s21_is_uncorrect_matrix(A) || result == NULL) {
    return S21_ERROR;
  }
  if (!s21_square_matrix(A)) {
    return S21_CALC_ERROR;
  }
  if (code == S21_OK) {
    if (A->rows == 1 && A->columns == 1) {
      *result = A->matrix[0][0];
    } else {
      *result = s21_det(A, A->columns);
    }
  }
  return code;
}
