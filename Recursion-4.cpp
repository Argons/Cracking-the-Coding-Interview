# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

// Write a method to compute all permutations of a string.

vector<string> getPermutation(string &str, int index) {
    vector<string> result;
    if (index == 0) {
        result.push_back(str.substr(0, 1));
        return result;
    }
    vector<string> prev = getPermutation(str, index-1);
    for (int i = 0; i < prev.size(); i++) {
        for (int j = 0; j <= prev[0].size(); j++) {
            string temp = prev[i];
            temp.insert(j, str, index, 1);
            result.push_back(temp);
        }
    }
    return result;
}

vector<string> permutations(string &str) {
    sort(str.begin(), str.end());
    return getPermutation(str, str.length()-1);
}


int main() {
    string str = "live";
    vector<string> result = permutations(str);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
