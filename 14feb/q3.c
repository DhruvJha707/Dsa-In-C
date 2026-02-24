/*Set-1 
 
 Write a program to create a singly linked list.

Write a program to display all nodes of a linked list.

Insert a node at the beginning of the list.

Insert a node at the end of the list.

Insert a node at a given position.

Delete the first node.

Delete the last node.

Delete a node with a given value.

Count total nodes in the list.

Search an element in a linked list.*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    
    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at given position (1-based)
void insertAtPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }
    
    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete first node
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// Delete last node
void deleteLast() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Delete node by value
void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    if (head->data == value) {
        deleteFirst();
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Value not found!\n");
        return;
    }

    struct Node *delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
}

// Count nodes
int countNodes() {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Search element
int search(int value) {
    struct Node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == value)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1; // Not found
}

// Display list
void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d → ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete First Node\n5. Delete Last Node\n6. Delete by Value\n");
        printf("7. Display List\n8. Count Nodes\n9. Search Element\n10. Exit\n");
        
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPosition(value, pos);
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
            if (pos == -1)
                printf("Value not found!\n");
            else
                printf("Found at position %d\n", pos);
            break;

        case 10:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}