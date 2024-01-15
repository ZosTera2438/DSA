vector<int> levelOrder(TreeNode *root){
    vector<vector<int>> result;
    if (root == NULL)
        return result;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()){
        // get size of q to run loop on current level
        int size = q.size();
        vector<int> row(size);

        for (int i = 0; i < size; i++){
            // get current node from q
            TreeNode *node = q.front();
            q.pop();
            row.push_back(node);

            // push left and right nodes of current node in q
            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
        // after this level
        result.push_back(row);
    }
    return result;
}