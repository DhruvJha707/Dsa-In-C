/*Search an element in a linked list.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newNode;
    int n, i, key, pos = 1, found = 0;

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

    printf("Enter element to search: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (found)
        printf("Element found at position %d\n", pos);
    else
        printf("Element not found\n");

    return 0;
}