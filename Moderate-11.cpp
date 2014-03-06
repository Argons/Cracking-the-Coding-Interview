#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Design an algorithm to find all pairs of integers within an array which 
// sum to a specified value.

vector<vector<int> > findPairs(vector<int> &array, int sum) {
    // O(N^2)
    vector<vector<int> > ret;
    vector<int> item;
    sort(array.begin(), array.end());
    for (int i = 0; i < array.size()-1; i++) {
        if (array[i] == array[i+1])
            continue;
        int left = sum - array[i];
        for (int j = i+1; j < array.size(); j++) {
            if (array[j] == left) {
                item.push_back(array[i]);
                item.push_back(left);
                ret.push_back(item);
                item.clear();
            }
        }
    }
    return ret;
}

vector<vector<int> > findPairs2(vector<int> &array, int sum) {
    // O(N*logN)
    vector<vector<int> > ret;
    vector<int> item;
    sort(array.begin(), array.end());
    int start = 0, end = array.size()-1;
    while (start < end) {
        int curSum = array[start] + array[end];
        if (curSum == sum) {
            item.push_back(array[start]);
            item.push_back(array[end]);
            ret.push_back(item);
            item.clear();
            start++;
            end--;
        } else if (curSum > sum) {
            end--;
        } else {
            start++;
        }
    }
    return ret;
}

int main() {
    vector<int> array;
    int a[10] = {-2, -1, 0, 3, 5, 6, 7, 9, 13, 14};
    array.assign(a, a+10);
    int sum;
    cin >> sum;
    vector<vector<int> > pairs = findPairs(array, sum);
    for (int i = 0; i < pairs.size(); i++) {
        cout << "(" << pairs[i][0] << ", " << pairs[i][1] << ")" << endl;
    }
    pairs = findPairs2(array, sum);
    for (int i = 0; i < pairs.size(); i++) {
        cout << "(" << pairs[i][0] << ", " << pairs[i][1] << ")" << endl;
    }
    return 0;
}
