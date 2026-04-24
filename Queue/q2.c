/*double stack*/

#include <stdio.h>
#define MAX 100

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int x) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow\n");
        return;
    }
    arr[++top1] = x;
}

void push2(int x) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow\n");
        return;
    }
    arr[--top2] = x;
}

void pop1() {
    if (top1 == -1) {
        printf("Stack1 Underflow\n");
        return;
    }
    printf("%d popped from Stack1\n", arr[top1--]);
}

void pop2() {
    if (top2 == MAX) {
        printf("Stack2 Underflow\n");
        return;
    }
    printf("%d popped from Stack2\n", arr[top2++]);
}

void display() {
    printf("Stack1: ");
    for (int i = 0; i <= top1; i++)
        printf("%d ", arr[i]);

    printf("\nStack2: ");
    for (int i = MAX - 1; i >= top2; i--)
        printf("%d ", arr[i]);

    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1.Push Stack1\n2.Push Stack2\n3.Pop Stack1\n4.Pop Stack2\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push1(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                push2(val);
                break;

            case 3:
                pop1();
                break;

            case 4:
                pop2();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}