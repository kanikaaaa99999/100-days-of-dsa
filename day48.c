#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* newNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int countLeaves(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    TreeNode* root        = newNode(1);
    root->left            = newNode(2);
    root->right           = newNode(3);
    root->left->left      = newNode(4);
    root->left->right     = newNode(5);

    printf("Leaf Nodes: %d\n", countLeaves(root));
    return 0;
}