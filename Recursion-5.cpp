# include <iostream>
# include <vector>
# include <string>
using namespace std;

// Implement an algorithm to print all valid (e.g., properly opened and closed)
// combinations of n-pairs of parentheses.

// EXAMPLE:
// input: 3 (e.g., 3 pairs of parentheses)
// output: ()()(), ()(()), (())(), ((()))

void getPairs(int n, int left, int right,
              vector<string> &result,
              string str) {
    if (left == n) {
        result.push_back(str.append(n-right, ')'));
        return;
    }
    getPairs(n, left+1, right, result, str+'(');
    if (left > right) {
        getPairs(n, left, right+1, result, str+')');
    }
}

vector<string> combinations(int n) {
    vector<string> result;
    if (n > 0)
        getPairs(n, 0, 0, result, "");
    return result;
}


int main() {
    int n = 5;
    vector<string> result = combinations(n);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
