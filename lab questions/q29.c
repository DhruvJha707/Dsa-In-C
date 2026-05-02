/*Merge two sorted linked lists*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* merge(struct node *l1, struct node *l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct node *result = NULL;

    if (l1->data <= l2->data) {
        result = l1;
        result->next = merge(l1->next, l2);
    } else {
        result = l2;
        result->next = merge(l1, l2->next);
    }

    return result;
}

int main() {
    struct node *head1 = NULL, *head2 = NULL;
    struct node *temp = NULL, *newNode;
    int n1, n2, i;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);

    if (n1 <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter elements of first list in sorted order:\n");
    for (i = 0; i < n1; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head1 == NULL) {
            head1 = newNode;
            temp = head1;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n2);

    if (n2 <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter elements of second list in sorted order:\n");
    for (i = 0; i < n2; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head2 == NULL) {
            head2 = newNode;
            temp = head2;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    struct node *merged = merge(head1, head2);

    temp = merged;
    printf("Merged Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}