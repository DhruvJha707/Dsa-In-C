/*Reverse a linked list using recursion*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* reverse(struct node *head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct node *rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

int main() {
    struct node *head = NULL, *temp = NULL, *newNode;
    int n, i;

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

    head = reverse(head);

    temp = head;
    printf("Reversed Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}