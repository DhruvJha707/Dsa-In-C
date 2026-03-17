// Reverse a Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* reverse(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

int main() {

    struct Node* head = newNode(10);
    struct Node* second = newNode(20);
    struct Node* third = newNode(30);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    printf("Original List:\n");
    printList(head);

    head = reverse(head);

    printf("\nReversed List:\n");
    printList(head);

    return 0;
}