/*) Write a C program to check whether a given number is even or odd using the switch statement. Also, calculate and display the execution time using the clock() function from <time.h>.*/

#include <stdio.h>
#include <time.h>

int main() {
    int n;
    clock_t start, end;
    double execution_time;

    printf("Enter a number: ");
    scanf("%d", &n);

    start = clock();

    switch (n % 2) {
        case 0:
            printf("Even\n");
            break;
        case 1:
        case -1:
            printf("Odd\n");
            break;
    }

    end = clock();

    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}