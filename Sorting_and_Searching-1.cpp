# include <iostream>
using namespace std;

// You are given two sorted arrays, A and B, and A has a large enough buffer 
// at the end to hold B. Write a method to merge B into A in sorted order.

void mergeSortedArrays(int A[], int B[], int m, int n) {
    while (n > 0) {
        if (m > 0 && A[m-1] > B[n-1]) {
            A[m+n-1] = A[--m];
        }
        else {
            A[m+n-1] = B[--n];
        }
    }
}

int main() {
    int a[20] = {1, 3, 4, 6, 8, 9, 13};
    int b[20] = {0, 2, 5, 7, 10};
    mergeSortedArrays(a, b, 7, 5);
    for (int i = 0; i < 12; i++)
        cout << a[i] << " ";
    return 0;
}
