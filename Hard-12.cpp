#include <iostream>
#include <climits>
using namespace std;

// Given an NxN matrix of positive and negative integers, write code 
// to find the submatrix with the largest possible sum.    

// brute force: O(N^6) = O(N^4) matrices * O(N^2) compute sum of each matrix;
// use preprocessing to store the sum of submatrices: O(N^4) = O(N^4) * O(1).

const int MAX_N = 100;
int p[MAX_N][MAX_N], A[MAX_N][MAX_N];

void PreCompute(int n){
    // compute sum of all sub-matrices
    for (int i = 0; i <= n; ++i)
        p[0][i] = p[i][0] = 0;
    for (int i=1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + A[i][j];
        }
    }
}

int MaxSum(int n) {
    // O(N^3)
    int max_sum = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            // find the sub-array of max sum, take each item in the array as
            // the sum of all numbers in that column within row i and row j.
            int cur_sum = 0;
            for (int k = 1; k <= n; ++k) {
                // compute the sum of all numbers in kth column within row i-j
                int val = (p[j][k] - p[j][k-1]) - (p[i-1][k] - p[i-1][k-1]);
                if (cur_sum <= 0) {
                    cur_sum = val;
                } else {
                    cur_sum += val;
                }
                if (cur_sum > max_sum) {
                    max_sum = cur_sum;
                }
            }
        }
    }
    return max_sum;
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> A[i][j];
        }
    }
    PreCompute(n);
    cout << MaxSum(n) << endl;
    return 0;
}
