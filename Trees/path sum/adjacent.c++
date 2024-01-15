int maxPathSum(TreeNode* root) {
    int maxPath = INT_MIN;
    dfs(root, maxPath);
    return maxPath;
}
int dfs(TreeNode* root, int& maxPath) {
    if (root == NULL) {
        return 0;
    }
    
    int left = max(dfs(root->left, maxPath), 0);
    int right = max(dfs(root->right, maxPath), 0);
    
    int curPath = root->val + left + right;
    maxPath = max(maxPath, curPath);
    
    return root->val + max(left, right);
}