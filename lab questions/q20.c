/*Delete a node with a given value.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *prev = NULL, *newNode;
    int n, i, value, found = 0;

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

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        found = 1;
    } else {
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL) {
            prev->next = temp->next;
            free(temp);
            found = 1;
        }
    }

    if (!found)
        printf("Value not found\n");

    temp = head;
    printf("Updated Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}