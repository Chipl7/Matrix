#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  code_error code = S21_OK;
  if (s21_is_uncorrect_matrix(A) || result == NULL) {
    return S21_ERROR;
  }
  if (!s21_square_matrix(A)) {
    return S21_CALC_ERROR;
  }
  if (code == S21_OK) {
    s21_create_matrix(A->rows, A->columns, result);
    double determinant = s21_det(A, A->columns);
    int one_one = 1;
    if (A->rows == 1 && A->columns == 1) {
      result->matrix[0][0] = (1 / determinant);
      one_one = 0;
    }
    if (one_one == 1) {
      matrix_t matrix_one;
      matrix_t matrix_two;
      s21_calc_complements(A, &matrix_one);
      s21_transpose(&matrix_one, &matrix_two);
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = matrix_two.matrix[i][j] * (1 / determinant);
        }
      }
      s21_remove_matrix(&matrix_one);
      s21_remove_matrix(&matrix_two);
    }
  }
  return code;
}