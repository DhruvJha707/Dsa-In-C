/*Write a C program to read n elements into an array, traverse the array, and print all its elements. Also, calculate and display the execution time required for traversing the array using the clock() function from <time.h>.*/

#include <stdio.h>
#include <time.h>

int main() {
    int n, i;
    int arr[100];
    clock_t start, end;
    double execution_time;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    start = clock();

    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    end = clock();

    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nExecution time: %f seconds\n", execution_time);

    return 0;
}