#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_SUCCESS 1
#define S21_FAILURE 0

typedef enum s21_result {
  S21_OK = 0,
  S21_ERROR = 1,
  S21_CALC_ERROR = 2,
} code_error;

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int s21_square_matrix(matrix_t *result);
int s21_one_one_matrix(matrix_t *result);
int s21_is_uncorrect_matrix(matrix_t *result);
int s21_eq_rows_columns(matrix_t *A, matrix_t *B);
matrix_t *s21_find_minor(matrix_t *minor, int row, int column,
                         matrix_t *matrix);
double s21_det(matrix_t *minor, int size);
void s21_allocate_memory(matrix_t *result, code_error *code);