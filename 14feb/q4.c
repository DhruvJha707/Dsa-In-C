/*Reverse a singly linked list (iterative method).

Reverse a linked list using recursion.

Find the middle element of a linked list.

Detect whether a loop exists in a linked list.

Remove duplicates from a sorted linked list.

Find the nth node from the end.

Merge two sorted linked lists.

Check if a linked list is palindrome or not.

Split a linked list into two halves.

Find length of linked list recursively.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertPosition(int data, int pos) {
    if (pos == 1) {
        insertBeginning(data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteLast() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteByValue(int value) {
    if (head == NULL) return;
    if (head->data == value) {
        deleteFirst();
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;
    if (temp->next == NULL)
        printf("Value not found\n");
    else {
        struct Node* del = temp->next;
        temp->next = del->next;
        free(del);
    }
}

void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int search(int value) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

struct Node* reverseIterative(struct Node* headRef) {
    struct Node *prev = NULL, *curr = headRef, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* reverseRecursive(struct Node* headRef) {
    if (headRef == NULL || headRef->next == NULL)
        return headRef;
    struct Node* rest = reverseRecursive(headRef->next);
    headRef->next->next = headRef;
    headRef->next = NULL;
    return rest;
}

struct Node* findMiddle(struct Node* headRef) {
    struct Node *slow = headRef, *fast = headRef;
    if (headRef == NULL) return NULL;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int detectLoop(struct Node* headRef) {
    struct Node *slow = headRef, *fast = headRef;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

void removeDuplicates(struct Node* headRef) {
    struct Node* temp = headRef;
    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            struct Node* del = temp->next;
            temp->next = del->next;
            free(del);
        } else {
            temp = temp->next;
        }
    }
}

struct Node* nthFromEnd(struct Node* headRef, int n) {
    struct Node *mainPtr = headRef, *refPtr = headRef;
    for (int i = 0; i < n; i++) {
        if (refPtr == NULL) return NULL;
        refPtr = refPtr->next;
    }
    while (refPtr != NULL) {
        mainPtr = mainPtr->next;
        refPtr = refPtr->next;
    }
    return mainPtr;
}

struct Node* mergeSorted(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
    if (a->data <= b->data) {
        a->next = mergeSorted(a->next, b);
        return a;
    } else {
        b->next = mergeSorted(a, b->next);
        return b;
    }
}

int checkPalindrome() {
    if (head == NULL || head->next == NULL)
        return 1;
    struct Node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node* secondHalf = reverseIterative(slow->next);
    struct Node *p1 = head, *p2 = secondHalf;
    while (p2 != NULL) {
        if (p1->data != p2->data)
            return 0;
        p1 = p1->next;
        p2 = p2->next;
    }
    return 1;
}

void splitList(struct Node* headRef, struct Node** first, struct Node** second) {
    struct Node *slow = headRef, *fast = headRef;
    if (headRef == NULL) {
        *first = *second = NULL;
        return;
    }
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *first = headRef;
    *second = slow->next;
    slow->next = NULL;
}

int lengthRecursive(struct Node* headRef) {
    if (headRef == NULL) return 0;
    return 1 + lengthRecursive(headRef->next);
}

int main() {
    int choice, value, pos, n;
    struct Node *result, *half1, *half2;

    while (1) {
        printf("\n=============== MENU ===============\n");
        printf("1. Insert Beginning\n2. Insert End\n3. Insert Position\n");
        printf("4. Delete First\n5. Delete Last\n6. Delete by Value\n");
        printf("7. Display\n8. Count Nodes\n9. Search\n");
        printf("10. Reverse Iterative\n11. Reverse Recursive\n");
        printf("12. Find Middle\n13. Detect Loop\n14. Remove Duplicates\n");
        printf("15. Nth Node From End\n16. Check Palindrome\n");
        printf("17. Split List\n18. Recursive Length\n");
        printf("19. Exit\n");
        printf("====================================\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertBeginning(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertEnd(value);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertPosition(value, pos);
            break;

        case 4:
            deleteFirst();
            break;

        case 5:
            deleteLast();
            break;

        case 6:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteByValue(value);
            break;

        case 7:
            display();
            break;

        case 8:
            printf("Total nodes = %d\n", countNodes());
            break;

        case 9:
            printf("Enter value to search: ");
            scanf("%d", &value);
            pos = search(value);
            if (pos == -1) printf("Not found\n");
            else printf("Found at position %d\n", pos);
            break;

        case 10:
            head = reverseIterative(head);
            printf("List reversed\n");
            break;

        case 11:
            head = reverseRecursive(head);
            printf("List reversed recursively\n");
            break;

        case 12:
            result = findMiddle(head);
            if (result) printf("Middle element = %d\n", result->data);
            break;

        case 13:
            if (detectLoop(head)) printf("Loop detected\n");
            else printf("No loop\n");
            break;

        case 14:
            removeDuplicates(head);
            printf("Duplicates removed\n");
            break;

        case 15:
            printf("Enter n: ");
            scanf("%d", &n);
            result = nthFromEnd(head, n);
            if (result) printf("%dth element from end = %d\n", n, result->data);
            else printf("Out of range\n");
            break;

        case 16:
            if (checkPalindrome()) printf("Palindrome\n");
            else printf("Not palindrome\n");
            break;

        case 17:
            splitList(head, &half1, &half2);
            printf("First half: ");
            struct Node* temp = half1;
            while (temp) { printf("%d ", temp->data); temp = temp->next; }
            printf("\nSecond half: ");
            temp = half2;
            while (temp) { printf("%d ", temp->data); temp = temp->next; }
            printf("\n");
            break;

        case 18:
            printf("Recursive length = %d\n", lengthRecursive(head));
            break;

        case 19:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}