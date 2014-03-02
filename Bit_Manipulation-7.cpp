#include <iostream>
#include <vector>
using namespace std;

// An array A[1...n] contains all the integers from 0 to n except for 
// one number which is missing. In this problem, we cannot access an 
// entire integer in A with a single operation. The elements of A are 
// represented in binary, and the only operation we can use to access 
// them is “fetch the jth bit of A[i]”, which takes constant time. 

// Write code to find the missing integer. 
// Can you do it in O(n) time?

int fetch(int num, int j) {
    return (num >> j) & 1;
}

int findMissing(vector<int> &array, int bit) {
    if (bit >= 32)
        return 0;

    vector<int> oddIndices;
    vector<int> evenIndices;
    
    // the missing integer will cause inbalance at each bit 
    // of every integer in the array.
    for (int i = 0; i < array.size(); i++) {
        if (fetch(array[i], bit) == 0) {
            evenIndices.push_back(array[i]);
        } else {
            oddIndices.push_back(array[i]);
        }
    }
    // the LSB of missing integer is 0.
    if (oddIndices.size() >= evenIndices.size())
        return (findMissing(evenIndices, bit+1)) << 1;
    return ((findMissing(oddIndices, bit+1)) << 1) | 1;
}

int findMissing(vector<int> &array) {
    return findMissing(array, 0);
}

int main() {
    vector<int> array(100, 0);
    for (int i = 0; i < array.size(); i++) {
        array[i] = i;
    }
    int x;
    cin >> x;
    array.erase(array.begin()+x);
    cout << "the missing integer is " << findMissing(array) << endl;
    return 0;
}
