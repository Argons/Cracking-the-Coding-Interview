#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;

// Given two words of equal length that are in a dictionary, write a method to
// transform one word into another word by changing only one letter at a time. 
// The new word you get in each step must be in the dictionary.  

// EXAMPLE:
// Input: DAMP, LIKE
// Output: DAMP -> LAMP -> LIMP -> LIME -> LIKE

set<string> oneEditWords(const string &word) {
    // return the set of words by editing only one char in the word.
    set<string> ret;
    for (int i = 0; i < word.length(); i++) {
        string temp = word;
        for (char j = 'A'; j <= 'Z'; j++) {
            if (j != word[i]) {
                temp[i] = j;
                ret.insert(temp);
            }
        }
    }
    return ret;
}

vector<string> transformWord(const string &word, const string &target, 
                             set<string> &dict) {
    // modification of breadth-first search
    // use backtrack map to emulate graph
    // O(N * M), N: word.size(), M: number of like sized words in dictionary.
    map<string, string> backtrack;
    set<string> visited;
    queue<string> action;

    visited.insert(word);
    action.push(word);

    while (!action.empty()) {
        string w = action.front();
        action.pop();
        set<string> editSet = oneEditWords(w);  // traverse next level
        for (set<string>::iterator it = editSet.begin(); it != editSet.end();
             it++) {
            if (*it == target) {
                vector<string> ret;
                ret.push_back(target);
                while (true) {
                    ret.insert(ret.begin(), w);
                    if (backtrack.find(w) == backtrack.end())
                        break;
                    w = backtrack[w];
                }
                return ret;
            }
            if (dict.find(*it) != dict.end()) {
                if (visited.find(*it) == visited.end()) {
                    visited.insert(*it);
                    action.push(*it);  // breadth first
                    backtrack.insert(make_pair(*it, w));
                }
            }
        }
    }
}

int main() {
    string word = "DAMP";
    string target = "LIKE";
    set<string> dict;
    dict.insert("DAMP");
    dict.insert("LAMP");
    dict.insert("LIMP");
    dict.insert("LIME");
    dict.insert("LIKE");
    dict.insert("LAMB");
    dict.insert("DAMN");

    vector<string> ret = transformWord(word, target, dict);
    cout << ret[0];
    for (int i = 1; i < ret.size(); i++) {
        cout << " -> " << ret[i];
    }
    cout << endl;
    return 0;
}
