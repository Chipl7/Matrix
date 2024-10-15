#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  code_error code = S21_OK;
  if (s21_is_uncorrect_matrix(A) || result == NULL) {
    return S21_ERROR;
  }
  if (!s21_square_matrix(A)) {
    return S21_CALC_ERROR;
  }
  if (code == S21_OK) {
    s21_create_matrix(A->rows, A->columns, result);
    if (A->rows == 1 && A->columns == 1) {
      result->matrix[0][0] = A->matrix[0][0];
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t temp;
          s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
          s21_find_minor(A, i, j, &temp);
          result->matrix[i][j] =
              ((i + j) % 2 == 0 ? 1 : -1) * s21_det(&temp, temp.columns);
          s21_remove_matrix(&temp);
        }
      }
    }
  }
  return code;
}
