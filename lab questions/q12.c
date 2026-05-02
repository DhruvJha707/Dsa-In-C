/*Write a C program to implement Binary Search on a sorted array. The program should:
    •Accept the number of elements from the user.
    •Read the elements in sorted order.
    •Accept a key value to search.
    •Perform Binary Search to find the element.
    •Display the index if found, otherwise print “Element Not
      found.
   •Count the number of comparisons made.
   •Measure and display the execution time using the clock()  
     function.

*/

#include <stdio.h>
#include <time.h>

int main() {
    int arr[100], n, i, key;
    int low = 0, high, mid;
    int found = 0, comparisons = 0;
    clock_t start, end;
    double execution_time;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter elements in sorted order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    high = n - 1;

    start = clock();

    while (low <= high) {
        mid = (low + high) / 2;
        comparisons++;

        if (arr[mid] == key) {
            found = 1;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    end = clock();

    if (found)
        printf("Element found at index %d\n", mid);
    else
        printf("Element Not found\n");

    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Total comparisons: %d\n", comparisons);
    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}