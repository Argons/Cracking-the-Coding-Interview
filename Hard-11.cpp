#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Imagine you have a square matrix, where each cell is filled with 
// either black or white. Design an algorithm to find the maximum 
// subsquare such that all four borders are filled with black pixels.

struct square {
    int row, col, size;
    square(int r = 0, int c = 0, int s = 0) : row(r), col(c), size(s) {}
};

bool isSquare(vector<vector<int> > &matrix, int row, int col, int size) {
    for (int i = 0; i < size; i++){
        if (matrix[row][col+i] == 1)
            return false;
        if (matrix[row+size-1][col+i] == 1)
            return false;
        if (matrix[row+i][col] == 1)
            return false;
        if (matrix[row+i][col+size-1] == 1)
            return false;
    }
    return true;
}

square findSquare(vector<vector<int> > &matrix) {
    square sq;
    int maxSize = 0;
    int col = 0;
    while (matrix.size()-col > maxSize) {
        for (int row = 0; row < matrix.size(); row++) {
            int size = matrix.size() - max(row, col);
            while (size > maxSize) {
                if (isSquare(matrix, row, col, size)) {
                    maxSize = size;
                    sq.row = row;
                    sq.col = col;
                    sq.size = size;
                    break;
                }
                size--;
            }
        }
        col++;
    }
    return sq;
}
    
int main() {
    return 0;
}
