/*Write a C program to perform insertion in an array. 
     The program should allow the user to:
• Insert an element at the beginning of the array, or
• Insert an element at any specified index.
     The program should then display the updated array and
     calculate the execution time of the insertion operation using
     clock() function.
*/

#include <stdio.h>
#include <time.h>

int main() {
    int arr[100], n, i, choice, pos, element;
    clock_t start, end;
    double execution_time;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 100) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("1. Insert at beginning\n2. Insert at position\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter element to insert: ");
    scanf("%d", &element);

    start = clock();

    if (choice == 1) {
        for (i = n; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = element;
        n++;
    } 
    else if (choice == 2) {
        printf("Enter position (0 to %d): ", n);
        scanf("%d", &pos);

        if (pos < 0 || pos > n) {
            printf("Invalid position\n");
            return 0;
        }

        for (i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = element;
        n++;
    } 
    else {
        printf("Invalid choice\n");
        return 0;
    }

    end = clock();

    printf("Updated array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nExecution time: %f seconds\n", execution_time);

    return 0;
}