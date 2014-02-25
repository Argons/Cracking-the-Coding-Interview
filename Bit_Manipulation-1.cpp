# include <iostream>
using namespace std;
 
// You are given two 32-bit numbers, N and M, and two bit positions, i and j.
// Write a method to set all bits between i and j in N equal to M.
// (e.g., M becomes a substring of N located at i and starting at j)

// EXAMPLE:
// Input: N = 10000000000, M = 10101, i = 2, j = 6
// Output: N = 10001010100

int setBits(int N, int M, int i, int j) {
    // divide binary N into 3 parts by bit i and j.
    M = M << i;
    int after_i = N - ((N >> i) << i);
    N = (N >> j) << j;
    return N | M | after_i;
}

int main() {
    int n = 64, m = 5, i = 2, j = 4;
    cout << setBits(n, m, i, j) << endl;
    return 0;
}
