#include <stdio.h>

int main() {
    int arr[100], n, i, x, y, index;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    if (n > 100) {
        printf("Overflow! Initial size exceeds array limit.\n");
        return 0;
    
    }
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }



    printf("Enter element to insert at beginning: ");
    scanf("%d", &x);

    for (i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
    n++;



    printf("After inserting at beginning: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");



    
    printf("Enter element to insert: ");
    scanf("%d", &y);

    printf("Enter index: ");
    scanf("%d", &index);

    for (i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = y;
    n++;


    printf("After inserting at index %d: ", index);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
