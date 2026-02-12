// matrix addition

#include <stdio.h>

int main() {
    int a[10][10], b[10][10], result[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);


    if (c1 != c2 || r1 != r2) {
        printf("Matrix addition not possible!\n");
        return 0;
    }


    // Input first matrix
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);


    // Input second matrix
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);


    // Add matrices
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    // Display result
    printf("Resultant Matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
