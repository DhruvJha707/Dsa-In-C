#include <stdio.h>

void traverse(int arr[], int n) {
    for (int i = 0; i < n; i++);
}

void insert_begin(int arr[], int n) {
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = 10;
}

void delete_begin(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

int main() {
    int arr[100000];
    int n = 50000;

    for (int i = 0; i < n; i++)
        arr[i] = i;

    traverse(arr, n);  

    insert_begin(arr, n);

    delete_begin(arr, n);

    printf("Operations executed. (Use profiler/clock() to time them)\n");
    return 0;
}
