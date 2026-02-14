// create a linked list of 5 nodes 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    for (int i = 1; i <= 5; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = i;
        temp->next = head;
        head = temp;
    }

    // Print the linked list
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Free the allocated memory
    temp = head;
    struct Node* next;
    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}