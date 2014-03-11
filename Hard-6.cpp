#include <iostream>
#include <vector>
using namespace std;

// Describe an algorithm to find the largest 1 million numbers in 1 billion numbers.
// Assume that the computer memory can hold all one billion numbers.

vector<int> findFirstMillion(vector<int> &array) {
    // 1. Sort the array, return the first million items:  O(N*logN);
    // 2. Max heap, create a Min-heap of size M:  O(N*logM), M = 1,000,000;
    // 3. Selection Rank, find the Mth largest item first:  O(N).
}

int kthLargest(vector<int> &array, int k) {
    if (array.size() == 1)
        return array[0];

    int pivot = array[0];
    vector<int> left, right;
    for (int i = 1; i < array.size(); i++) {
        if (array[i] < pivot) {
            left.push_back(array[i]);
        } else {
            right.push_back(array[i]);
        }
    }

    if (right.size() >= k) 
        return kthLargest(right, k);
    if (right.size()+1 == k)
        return pivot;
    return kthLargest(left, k-right.size()-1);
}

int main() {
    int a[10] = {5, 2, 6, 3, 9, 1, 0, 8};
    vector<int> array;
    array.assign(a, a+8);
    int k;
    cin >> k;
    cout << kthLargest(array, k) << endl;
    return 0;
}
