# include <iostream>
using namespace std;

// Given an image represented by an NxN matrix, where each pixel in the 
// image is 4 bytes, write a method to rotate the image by 90 degrees.

void rotateMatrix(int **matrix, int n) {
    // rotate by layers, altogether n/2 layers in the matrix.
    for (int i = 0; i < n/2; i++) {
        int start = i;
        int end = n - 1 - i;
        for (int j = start; j < end; j++) {
            int top = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];          // left -> top
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];  // bottom -> left
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];  // right -> bottom
            matrix[j][n-1-i] = top;                   // top -> right
        }
    }
}
