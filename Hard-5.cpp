#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// You have a large text file containing words. Given any two words,
// find the shortest distance (in terms of number of words) between 
// them in the file. Can you make the searching operation in O(1) 
// time? What about the space complexity for your solution?

int distace(vector<string> &text, string &word1, string &word2) {
    // O(N): traverse text;
    // or use hash table to store indexes of word1 and word2 in the text.
    int pos1 = INT_MIN, pos2 = INT_MIN;
    int minDistance = INT_MAX;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == word1) {
            pos1 = i;
            minDistance = min(pos1-pos2, minDistance);
        } else if (text[i] == word2) {
            pos2 = i;
            minDistance = min(pos2-pos1, minDistance);
        }
    }
    return minDistance;
}

int main() {
    return 0;
}
