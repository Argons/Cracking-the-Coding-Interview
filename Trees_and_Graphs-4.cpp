# include <iostream>
# include <vector>
# include <queue>
# include <list>
using namespace std;

// Given a binary search tree, design an algorithm which creates a linked list
// of all the nodes at each depth (i.e., if you have a tree with depth D, you
// will have D linked lists)

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<list<TreeNode*> > createLevelLists(TreeNode *root) {
    // Breadth First Traversal
    vector<list<TreeNode*> > levelLists;
    list<TreeNode*> level;
    if (root == NULL)
        return levelLists;
    queue<TreeNode*> nodes;
    nodes.push(root);
    nodes.push(NULL);  // mark the end of a level.
    while (!nodes.empty()) {
        TreeNode *current = nodes.front();
        nodes.pop();
        if (current == NULL) {
            levelLists.push_back(level);
            level.clear();
            if (nodes.empty())
                break;
            nodes.push(NULL);
        } 
        else {
            level.push_back(current);
            if (current->left != NULL)
                nodes.push(current->left);
            if (current->left != NULL)
                nodes.push(current->right);
        }
    }
    return levelLists;
}

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(7);
    vector<list<TreeNode*> > ret = createLevelLists(root);
    return 0;
}
