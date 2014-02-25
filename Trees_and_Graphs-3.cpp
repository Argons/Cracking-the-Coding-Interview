# include <iostream>
using namespace std;

// Given a sorted (increasing order) array, write an algorithm to 
// create a binary tree with minimal height.

TreeNode* build(vector<int> &array, int start, int end) {
    if (start > end)
        return NULL;
    int mid = (start+end) / 2;
    TreeNode *root = new TreeNode(array[mid]);
    root->left  = build(array, start, mid-1);
    root->right = build(array, mid+1, end);
    return root;
}

TreeNode* buildTree(vector<int> array) {
    return build(array, 0, array.size()-1);
}
