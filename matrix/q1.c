#include <stdio.h>

void addMatrix(int A[10][10], int B[10][10], int C[10][10], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subMatrix(int A[10][10], int B[10][10], int C[10][10], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void multiplyMatrix(int A[10][10], int B[10][10], int C[10][10],
                    int r1, int c1, int r2, int c2) {

    if (c1 != r2) {
        printf("Multiplication not possible.\n");
        return;
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[10][10], B[10][10], C[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    // Addition (only if same size)
    if (r1 == r2 && c1 == c2) {
        addMatrix(A, B, C, r1, c1);
        printf("\nAddition Result:\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++)
                printf("%d ", C[i][j]);
            printf("\n");
        }
    } else {
        printf("\nAddition not possible.\n");
    }

    // Subtraction (only if same size)
    if (r1 == r2 && c1 == c2) {
        subMatrix(A, B, C, r1, c1);
        printf("\nSubtraction Result:\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++)
                printf("%d ", C[i][j]);
            printf("\n");
        }
    } else {
        printf("\nSubtraction not possible.\n");
    }

    // Multiplication
    multiplyMatrix(A, B, C, r1, c1, r2, c2);
    if (c1 == r2) {
        printf("\nMultiplication Result:\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++)
                printf("%d ", C[i][j]);
            printf("\n");
        }
    }

    return 0;
}
