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

int height(TreeNode* root) {
    if (!root) return 0;
    int left  = height(root->left);
    int right = height(root->right);
    return 1 + (left > right ? left : right);
}

int main() {
    TreeNode* root        = newNode(1);
    root->left            = newNode(2);
    root->right           = newNode(3);
    root->left->left      = newNode(4);
    root->left->right     = newNode(5);

    printf("Height: %d\n", height(root));
    return 0;
}