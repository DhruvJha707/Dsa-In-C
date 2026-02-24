//pointer to an array
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;  

    printf("Array elements using pointer:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

//  second element pointer storage
    int secondElement = *(ptr + 1);
    printf("Second element: %d\n", secondElement);
    return 0;
