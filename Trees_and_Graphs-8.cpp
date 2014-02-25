# include <vector>
using namespace std;

// You are given a binary tree in which each node contains a value. Design an 
// algorithm to print all paths which sum up to that value. Note that it can 
// be any path in the tree - it does not have to start at the root.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void getPath(TreeNode *root, int sum, vector<vector<int> > &result,
             vector<int> &path) {
    if (root == NULL)
        return;

    path.push_back(root->val);
    if (root->left == NULL && root->right == NULL && sum == root->val) {
        result.push_back(path);
        path.pop_back();
        return;
    }
    getPath(root->left,  sum-root->val, result, path);
    getPath(root->right, sum-root->val, result, path);
    path.pop_back();
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > result;
    vector<int> path;
    getPath(root, sum, result, path);
    return result;
}
