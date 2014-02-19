# include <iostream>
# include <vector>
using namespace std;

// Given a sorted array of n integers that has been rotated an unknown number of
// times, give an O(log n) algorithm that finds an element in the array. 
// You may assume that the array was originally sorted in increasing order.

// EXAMPLE:
// Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
// Output: 8 (the index of 5 in the array)

int findElement(vector<int> &array, int num) {
    int size = array.size();
    int start = 0, end = size - 1, mid;

    while (start <= end) {
        mid = (start+end) / 2;
        if (num == array[mid])
            return mid;
        else if (array[start] < array[end]) {
            if (num > array[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        else {
            // decide num belongs to which part of array.
            if (num < array[mid])
                end = mid - 1;
            else if (num <= array[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int num[12] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    vector<int> array;
    array.assign(num, num+12);
    cout << findElement(array, 5) << endl;
    return 0;
}
