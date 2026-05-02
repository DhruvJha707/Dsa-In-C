/* Write a C program to perform addition of two matrices. 
    The program should:
1.	Accept the number of rows and columns from the user.
2.	Read two matrices of the same order.
3.	Compute their sum.
4.	Count the total number of addition operations performed.
5.	Measure and display the execution time using the clock() function
*/

#include <stdio.h>
#include <time.h>

int main() {
    int r, c, i, j;
    int a[50][50], b[50][50], sum[50][50];
    int count = 0;
    clock_t start, end;
    double execution_time;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    if (r <= 0 || c <= 0 || r > 50 || c > 50) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &b[i][j]);

    start = clock();

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            count++;
        }
    }

    end = clock();

    printf("Sum of matrices:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Total addition operations: %d\n", count);
    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}