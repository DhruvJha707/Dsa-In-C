//Remove loop in Linked List 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void removeLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Detect loop
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // If loop exists
    if (slow == fast) {
        slow = head;

        // Find start of loop
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove loop
        fast->next = NULL;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {

    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Creating loop (5 -> 3)
    head->next->next->next->next->next = head->next->next;

    removeLoop(head);

    printf("Linked List after removing loop:\n");
    printList(head);

    return 0;
}