//Find length of Loop

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countLoopNodes(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {   // loop detected
            int count = 1;
            struct Node* temp = slow;

            while (temp->next != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }

    return 0; // no loop
}

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {

    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Creating loop (5 -> 3)
    head->next->next->next->next->next = head->next->next;

    int len = countLoopNodes(head);

    if(len)
        printf("Length of Loop: %d", len);
    else
        printf("No Loop Found");

    return 0;
}