#include <iostream>
#include <vector>
using namespace std;

// You are given an array of integers (both positive and negative). 
// Find the continuous sequence with the largest sum. Return the sum.
// EXAMPLE
// Input: {2, -8, 3, -2, 4, -10}
// Output: 5 (i.e., {3, -2, 4} )

int maxSum(vector<int> &array) {
    int max = 0, curMax = 0;
    int i = 0, j = array.size();

    for (int i = 0; i < array.size(); i++) {
        if (max + array[i] < 0) {
            max = 0;
        } else {
            max += array[i];
        }
        curMax = curMax > max ? curMax : max;
    }
    return curMax;
}

int main() {
    int a[10] = {2, -8, 3, -2, 4, -10};
    vector<int> array;
    array.assign(a, a+6);
    cout << maxSum(array) << endl;
    return 0;
}
