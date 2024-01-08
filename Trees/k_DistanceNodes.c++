void printkdistanceNodeDown(Node* root, int k){
    if (root == NULL || k < 0) return;
 
    // If we reach a k distant node, print it
    if (k==0){
        cout<< root->data<<endl;
        return;
    }
 
    // Recur for left and right subtrees
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}
 
int printkdistanceNode(Node* root, Node* target , int k){
    if (root == NULL) return -1;

    // target found, print nodes down to the target
    if (root == target){
        printkdistanceNodeDown(root, k);
        return 0;
    }
 
    // Recur for left subtree
    int dl = printkdistanceNode(root->left, target, k);
 
    // Check if target node was found in left subtree
    if (dl != -1){
        // If root is at distance k from target, print root
        if (dl + 1 == k)
            cout<<root->data<<endl;
 
        // Else go to right subtree and print all k-dl-2 nodes
        else
            printkdistanceNodeDown(root->right, k-dl-2);
 
        // Add 1 to the distance and return value for parent calls
        return 1 + dl;
    }
 
    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
    // we reach here only when node was not found in left subtree
    int dr = printkdistanceNode(root->right, target, k);
    if (dr != -1){
        if (dr + 1 == k)
            cout<<root->data<<endl;
        else
            printkdistanceNodeDown(root->left, k-dr-2);
        return 1 + dr;
    }
 
    // If target not found in left nor right subtree
    return -1;
}