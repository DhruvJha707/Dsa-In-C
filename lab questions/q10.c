/*Write a C program to define a structure for storing employee details (ID, name, and salary). Use a pointer to the structure to input and display the employee details. Also, calculate and display the execution time using the clock() function.*/

#include <stdio.h>
#include <time.h>

struct employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct employee emp;
    struct employee *ptr;
    clock_t start, end;
    double execution_time;

    ptr = &emp;

    start = clock();

    printf("Enter ID: ");
    scanf("%d", &ptr->id);

    printf("Enter Name: ");
    scanf("%s", ptr->name);

    printf("Enter Salary: ");
    scanf("%f", &ptr->salary);

    printf("\nEmployee Details:\n");
    printf("ID: %d\n", ptr->id);
    printf("Name: %s\n", ptr->name);
    printf("Salary: %.2f\n", ptr->salary);

    end = clock();

    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}