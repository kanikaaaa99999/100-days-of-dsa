int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    struct TreeNode** stack = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*));
    int top = -1, idx = 0;

    if (root) stack[++top] = root;

    while (top >= 0) {
        struct TreeNode* node = stack[top--];
        result[idx++] = node->val;

        if (node->right) stack[++top] = node->right;
        if (node->left)  stack[++top] = node->left;
    }

    free(stack);
    *returnSize = idx;
    return result;
}