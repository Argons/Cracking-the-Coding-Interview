# include <iostream>
using namespace std;

// Write an algorithm to find the ‘next’ node (e.g., in-order successor) of a 
// given node in a binary search tree where each node has a link to its parent.

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

TreeNode* leftMost(TreeNode *node) {
    if (node == NULL)
        return NULL;
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

TreeNode* nextNode(TreeNode *node) {
    if (node == NULL)
        return NULL;
    // n could be the left / right node.
    TreeNode *p = node->parent;
    if (p == NULL || p->right != NULL)
        return leftMost(node->right);
    if (node == p->right) {
        // when n is the last node of the traversal in the left branch,
        // trace upwards to find its parent.
        while (node != p->left && p != NULL) {
            node = p;
            p = node->parent;
        }
    }
    return p;
}

int main() {
    return 0;
}
