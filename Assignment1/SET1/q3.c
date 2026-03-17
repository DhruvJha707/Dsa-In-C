// Delete a Node in Single Linked...

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteNode(struct Node** head, int key) {

    struct Node *temp = *head, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not present
    if (temp == NULL)
        return;

    // Unlink node
    prev->next = temp->next;

    free(temp);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {

    struct Node* head = NULL;

    // Creating list: 10 -> 20 -> 30 -> 40
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;

    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 20;

    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 30;

    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 40;
    head->next->next->next->next = NULL;

    deleteNode(&head, 30);

    printf("Linked List after deletion:\n");
    printList(head);

    return 0;
}