int kthSmallest(TreeNode* root, int k) {
    int result = 0;
    inorder(root, k, result);
    return result;
}

void inorder(TreeNode* root, int& k, int& result) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, k, result);
    k--;
    if (k == 0) {
        result = root->val;
        return;
    }
    inorder(root->right, k, result);
}