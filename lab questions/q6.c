/*Write a C program to:
      • Define a structure for a node of a singly linked list.
        • Dynamically allocate memory for 5 nodes.
          • Link the nodes together to form a linked list.
          • Display the linked list in the format: data -> data -> ... ->       
        NULL.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    int i;

    for (i = 0; i < 5; i++) {
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

    temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}