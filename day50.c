#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create node
struct node* createNode(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert (to build BST)
struct node* insert(struct node* root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// Search in BST
int search(struct node* root, int key) {
    if (root == NULL)
        return 0;   // not found

    if (root->data == key)
        return 1;   // found

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    int n, x, key;
    struct node* root = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Insert elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    // Input key to search
    scanf("%d", &key);

    // Output result
    if (search(root, key))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}