#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void input_matrix(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("Введите элемент [%d][%d]: ", i, j);
            scanf("%lf", &m->data[i][j]);
        }
    }
}

int main() {
        int r1, c1, r2, c2;
    int choice;

    printf("1 — сложение матриц\n");
    printf("2 — умножение матриц\n");
    printf("Выберите операцию: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nМатрица A:\nВведите строки и столбцы: ");
        scanf("%d %d", &r1, &c1);

        printf("Матрица B:\nВведите строки и столбцы: ");
        scanf("%d %d", &r2, &c2);

        if (r1 != r2 || c1 != c2) {
            printf("Нельзя сложить матрицы разных размеров.\n");
            return 0;
        }

        Matrix* A = create_matrix(r1, c1);
        Matrix* B = create_matrix(r2, c2);

        printf("\nВвод A:\n");
        input_matrix(A);
        printf("\nВвод B:\n");
        input_matrix(B);

        Matrix* R = add(A, B);

        if (!R) {
            printf("Ошибка при сложении.\n");
        } else {
            printf("\nРезультат:\n");
            print_matrix(R);
            free_matrix(R);
        }

        free_matrix(A);
        free_matrix(B);
    }

    else if (choice == 2) {
        printf("\nМатрица A:\nВведите строки и столбцы: ");
        scanf("%d %d", &r1, &c1);

        printf("Матрица B:\nВведите строки и столбцы: ");
        scanf("%d %d", &r2, &c2);

        if (c1 != r2) {
            printf("Нельзя умножить: число столбцов A должно равняться строкам B.\n");
            return 0;
        }

        Matrix* A = create_matrix(r1, c1);
        Matrix* B = create_matrix(r2, c2);

        printf("\nВвод A:\n");
        input_matrix(A);
        printf("\nВвод B:\n");
        input_matrix(B);

        Matrix* R = multiply(A, B);

        if (!R) {
            printf("Ошибка при умножении.\n");
        } else {
            printf("\nРезультат:\n");
            print_matrix(R);
            free_matrix(R);
        }

        free_matrix(A);
        free_matrix(B);
    }

    else {
        printf("Неизвестная операция.\n");
    }

    return 0;
}