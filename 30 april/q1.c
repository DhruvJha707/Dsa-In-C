/*wap to find the total number of leaf nodes,non-leaf nodes and number nodes */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* createTree() {
    int val;
    printf("Enter value (-1 for no node): ");
    scanf("%d", &val);

    if (val == -1)
        return NULL;

    struct Node* root = createNode(val);

    printf("Enter left child of %d\n", val);
    root->left = createTree();

    printf("Enter right child of %d\n", val);
    root->right = createTree();

    return root;
}

int countTotal(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countTotal(root->left) + countTotal(root->right);
}

int countLeaf(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

int countNonLeaf(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 0;

    return 1 + countNonLeaf(root->left) + countNonLeaf(root->right);
}

int main() {
    struct Node* root;

    printf("Create Binary Tree:\n");
    root = createTree();

    printf("\nTotal nodes = %d\n", countTotal(root));
    printf("Leaf nodes = %d\n", countLeaf(root));
    printf("Non-leaf nodes = %d\n", countNonLeaf(root));

    return 0;
}45