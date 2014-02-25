# include <iostream>
using namespace std;

// Implement a function to check if a tree is balanced. For the purposes of
// this question, a balanced tree is defined to be a tree such that no two 
// leaf nodes differ in distance from the root by more than one.

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int value) : val(value), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *root) {
    if (root == NULL)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

bool isBalanced(TreeNode *root) {
    if (root == NULL)
        return true;
    if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
