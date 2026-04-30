/*Write a C program to print the word "UPES" n times (where n is entered by the user). If the user enters a non-positive number, display "Invalid input". Also, calculate and display the total execution time taken by the program using the clock() function.*/

#include <stdio.h>
#include <time.h>

int main() {
    int n, i;
    clock_t start, end;
    double execution_time;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    start = clock();

    for (i = 0; i < n; i++) {
        printf("UPES\n");
    }

    end = clock();

    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}