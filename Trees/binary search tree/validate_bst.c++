/*
    Given root of binary tree, determine if it's valid (left all < curr, right all > curr)
    
    Inorder traversal & check if prev >= curr, recursive/iterative solutions
*/


bool isValidBST(TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}
bool helper(TreeNode* root, long left, long right){
    if (!root)
        return true;
    if (root->val < right && root->val > left){
        return helper(root->left, left, root->val) && helper(root->right, root->val, right);
    }
    return false;
}