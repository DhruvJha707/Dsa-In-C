/*Find the nth node from the end*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newNode;
    struct node *first, *second;
    int n, i, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter n (nth node from end): ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    first = head;
    second = head;

    for (i = 0; i < pos; i++) {
        if (first == NULL) {
            printf("Position exceeds list length\n");
            return 0;
        }
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    printf("Nth node from end: %d\n", second->data);

    return 0;
}