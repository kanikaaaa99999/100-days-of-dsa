int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;

    void dfs(struct TreeNode* node) {
        if (!node) return;
        dfs(node->left);
        res[(*returnSize)++] = node->val;
        dfs(node->right);
    }
    dfs(root);
    return res;
}