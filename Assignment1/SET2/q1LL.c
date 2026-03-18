#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to count matching nodes 
int countSame(struct Node* left, struct Node* right) {
    int count = 0;

    while (left != NULL && right != NULL) {
        if (left->data != right->data)
            break;

        count++;
        left = left->next;
        right = right->next;
    }

    return count;
}

// Function to find longest palindrome length
int longestPalindrome(struct Node* head) {
    struct Node *prev = NULL, *curr = head;
    int maxLen = 0;

    while (curr != NULL) {
        struct Node* next = curr->next;

        // Reverse current link
        curr->next = prev;

        // Check odd length palindrome
        int odd = 2 * countSame(prev, next) + 1;

        // Check even length palindrome
        int even = 2 * countSame(curr, next);

        // Update maximum
        if (odd > maxLen) maxLen = odd;
        if (even > maxLen) maxLen = even;

        // Move pointers forward
        prev = curr;
        curr = next;
    }

    return maxLen;
}

// Insert at beginning 
struct Node* insert(struct Node* head, int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = head;
    return temp;
}

int main() {
    struct Node* head = NULL;

    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 2);

    printf("Longest Palindrome Length = %d", longestPalindrome(head));

    return 0;
}