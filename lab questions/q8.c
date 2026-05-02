/*Write a C program that prints the values of i starting from 1 and repeatedly doubles it (i = i * 2) until it becomes greater than a user-entered number n. If n is not positive, display "Invalid input". Also, measure and display the execution time using the clock() function.*/

#include <stdio.h>
#include <time.h>

int main() {
    int n, i = 1;
    clock_t start, end;
    double execution_time;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    start = clock();

    while (i <= n) {
        printf("%d ", i);
        i = i * 2;
    }

    end = clock();

    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nExecution time: %f seconds\n", execution_time);

    return 0;
}