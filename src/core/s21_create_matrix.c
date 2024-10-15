#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  code_error code = S21_ERROR;
  if (result != NULL && rows >= 1 && columns >= 1) {
    code = S21_OK;
    result->rows = rows;
    result->columns = columns;
    s21_allocate_memory(result, &code);
  }
  return code;
}
