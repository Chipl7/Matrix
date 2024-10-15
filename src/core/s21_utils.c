#include "../s21_matrix.h"

int s21_square_matrix(matrix_t *result) {
  return result != NULL && (result->rows == result->columns);
}

int s21_one_one_matrix(matrix_t *result) {
  return result != NULL && result->rows == 1 && result->columns == 1;
}

int s21_is_uncorrect_matrix(matrix_t *result) {
  return (result == NULL || result->rows < 1 || result->columns < 1);
}

int s21_eq_rows_columns(matrix_t *A, matrix_t *B) {
  return (A == NULL && B == NULL) ||
         (A != NULL && B != NULL &&
          (A->rows == B->rows && A->columns == B->columns));
}

double s21_det(matrix_t *minor, int size) {
  double determinant = 0;
  if (s21_one_one_matrix(minor)) {
    determinant = minor->matrix[0][0];
  } else {
    matrix_t matrix;
    s21_create_matrix(size - 1, size - 1, &matrix);
    for (int i = 0; i < minor->columns; i++) {
      s21_find_minor(minor, 0, i, &matrix);
      double a = ((i % 2 == 0 ? 1 : -1) * minor->matrix[0][i] *
                  s21_det(&matrix, size - 1));
      determinant += a;
    }
    s21_remove_matrix(&matrix);
  }
  return determinant;
}

matrix_t *s21_find_minor(matrix_t *minor, int row, int column,
                         matrix_t *matrix) {
  int new_i = 0, new_j = 0;
  for (int i = 0; i < minor->rows; i++) {
    if (i != row) {
      new_j = 0;
      for (int j = 0; j < minor->columns; j++) {
        if (j != column) {
          matrix->matrix[new_i][new_j] = minor->matrix[i][j];
          new_j++;
        }
      }
      new_i++;
    }
  }
  return matrix;
}

void s21_allocate_memory(matrix_t *result, code_error *code) {
  result->matrix = (double **)calloc(result->rows, sizeof(double *));
  if (result->matrix == NULL) {
    free(result->matrix);
    result->matrix = NULL;
    *code = S21_ERROR;
  }
  if (*code == S21_OK) {
    for (int i = 0; i < result->rows && *code == S21_OK; i++) {
      result->matrix[i] = (double *)calloc(result->columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        *code = S21_ERROR;
        for (int j = 0; j < i; j++) {
          free(result->matrix[j]);
        }
        free(result->matrix);
        result->matrix = NULL;
      }
    }
  }
}
