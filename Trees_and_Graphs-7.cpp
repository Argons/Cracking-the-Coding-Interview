# include <iostream>
using namespace std;

// You have two very large binary trees: T1, with millions of nodes, and T2,
// with hundreds of nodes. 
// Create an algorithm to decide if T2 is a subtree of T1.

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int value): val(value), left(NULL), right(NULL) {}
};

bool matchTree(TreeNode *root1, TreeNode *root2) {
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->val != root2->val)
        return false;
    return matchTree(root1->left, root2->left) &&
           matchTree(root1->right, root2->right);
}

bool isSubTree(TreeNode *root1, TreeNode *root2) {
    if (root2 == NULL)
        return true;
    if (root1 == NULL)
        return false;
    if (root1->val == root2->val)
        return matchTree(root1, root2);
    return isSubTree(root1->left, root2) ||
           isSubTree(root1->right, root2);
}
