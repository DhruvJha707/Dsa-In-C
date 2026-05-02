/*Detect whether a loop exists in a linked list*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp = NULL, *newNode;
    struct node *slow, *fast;
    int n, i, hasLoop = 0;

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

    int pos;
    printf("Enter position to create loop (0 for no loop): ");
    scanf("%d", &pos);

    if (pos > 0 && pos <= n) {
        struct node *loopNode = head;
        for (i = 1; i < pos; i++)
            loopNode = loopNode->next;
        temp->next = loopNode;
    }

    slow = head;
    fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            hasLoop = 1;
            break;
        }
    }

    if (hasLoop)
        printf("Loop detected in linked list\n");
    else
        printf("No loop in linked list\n");

    return 0;
}