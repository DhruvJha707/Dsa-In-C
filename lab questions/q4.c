/*Write a C program to perform multiplication of two matrices.      
     The program should:
1.	Accept the number of rows and columns of both matrices from the user.
2.	Check whether matrix multiplication is possible.
3.	Compute the product of the matrices.
4.	Count the total number of multiplication operations performed.
5.	Measure and display the execution time using the clock() function.
*/

#include <stdio.h>
#include <time.h>

int main() {
    int r1, c1, r2, c2, i, j, k;
    int a[50][50], b[50][50], result[50][50];
    int count = 0;
    clock_t start, end;
    double execution_time;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible\n");
        return 0;
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    start = clock();

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
                count++;
            }
        }
    }

    end = clock();

    printf("Resultant matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Total multiplication operations: %d\n", count);
    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}