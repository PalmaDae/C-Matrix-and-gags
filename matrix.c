#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* create_matrix(int rows, int cols) {
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    if (!m) return NULL;

    m->rows = rows;
    m->cols = cols;

    m->data = (double**) malloc(sizeof(double*) * rows);
    if (!m->data) {
        free(m);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        m->data[i] = (double*) malloc(sizeof(double) * cols);
        if (!m->data[i]) {
            for (int j = 0; j < i; j++) free(m->data[j]);
            free(m->data);
            free(m);
            return NULL;
        }
    }

    return m;
}

void free_matrix(Matrix* m) {
    if (!m) return;
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

Matrix* add(const Matrix* a, const Matrix* b) {
    if (a->rows != b->rows || a->cols != b->cols) return NULL;

    Matrix* result = create_matrix(a->rows, a->cols);
    if (!result) return NULL;

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return result;
}

Matrix* multiply(const Matrix* a, const Matrix* b) {
    if (a->cols != b->rows) return NULL;

    Matrix* r = create_matrix(a->rows, b->cols);
    if (!r) return NULL;

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            r->data[i][j] = 0.0;
            for (int k = 0; k < a->cols; k++) {
                r->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    return r;
}

void print_matrix(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        printf("+");
        for (int j = 0; j < m->cols; j++)
            printf("--------+");
        printf("\n|");
        for (int j = 0; j < m->cols; j++)
            printf(" %6.2lf |", m->data[i][j]);
        printf("\n");
    }
    printf("\n");
}

