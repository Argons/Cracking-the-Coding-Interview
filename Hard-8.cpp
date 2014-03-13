#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Given a string s and an array of smaller strings T, design a method 
// to search s for each small string in T.   

class SuffixTreeNode {
private:
    map<char, SuffixTreeNode> children;
    char value;
    vector<int> indexes;
public:
    SuffixTreeNode() { }
    void insertString(const string &s, int index) {
        indexes.push_back(index);
        if (s.length() > 0) {
            value = s[0];
            SuffixTreeNode child;
            if (children.find(value) != children.end()) {
                child = children[value];
            } else {
                children.insert(make_pair(value, child));
            }
            string remainder = s.substr(1);
            child.insertString(remainder, index);
        }
    }
    vector<int> getIndexes(const string &s) {
        if (s.empty()) {
            return indexes;
        } else {
            char first = s[0];
            if (children.find(first) != children.end()) {
                string remainder = s.substr(1);
                return children[first].getIndexes(remainder);
            }
        }
        return vector<int>();
    }
};

class SuffixTree {
    SuffixTreeNode root;
public:
    SuffixTree(const string &s) {
        for (int i = 0; i < s.length(); i++) {
            string suffix = s.substr(i);
            root.insertString(suffix, i);
        }
    }
    vector<int> getIndexes(const string &s) {
        return root.getIndexes(s);
    }
};

vector<vector<int> > findStrings(const string &s, vector<string> &T) {
    SuffixTree tree(s);
    vector<vector<int> > ret;
    for (int i = 0; i < T.size(); i++) {
        vector<int> list = tree.getIndexes(T[i]);
        ret.push_back(list);
    }
    return ret;
}
    
int main() {
    string testString = "mississippi";
    vector<string> stringList;
    string str[5] = {"is", "sip", "hi", "sis"};
    stringList.assign(str, str+4);

    vector<vector<int> > ret = findStrings(testString, stringList);
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
