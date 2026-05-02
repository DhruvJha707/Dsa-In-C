/*Write a C program to perform Linear Search on an array. The program should:
  • Accept the number of elements from the user.
  • Read the array elements.
           • Accept an element to search.
    • Search for the element using Linear Search.
           • Display the position if found, otherwise print “Element Not
             Found”.
    • Measure and display the execution time using the clock()
       function.
*/

#include <stdio.h>
#include <time.h>

int main() {
    int arr[100], n, i, key, found = 0;
    clock_t start, end;
    double execution_time;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    start = clock();

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = 1;
            break;
        }
    }

    end = clock();

    if (found)
        printf("Element found at position %d\n", i + 1);
    else
        printf("Element Not Found\n");

    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}