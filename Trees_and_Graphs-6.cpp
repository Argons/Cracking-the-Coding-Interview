# include <iostream>
using namespace std;

// Design an algorithm and write code to find the first common ancestor of two 
// nodes in a binary tree. Avoid storing additional nodes in a data structure.
// NOTE: This is not necessarily a binary search tree.

bool contain(TreeNode *root, TreeNode *n) {
    if (root == NULL)
        return false;
    if (root == n)
        return true;
    return contain(root->left, n) || contain(root->right, n);
}

TreeNode* firstCommonAncestor(TreeNode *root, TreeNode *n1, TreeNode *n2) {
    if (contain(root->left, n1) && contain(root->left, n2))
        return firstCommonAncestor(root->left, n1, n2);
    if (contain(root->right, n1) && contain(root->right, n2))
        return firstCommonAncestor(root->right, n1, n2);
    return root;
}
