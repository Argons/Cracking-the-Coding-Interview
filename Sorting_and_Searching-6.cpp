# include <iostream>
using namespace std;

// Given a matrix in which each row and each column is sorted, 
// write a method to find an element in it.

bool search(int matrix[][5], int m, int n, int element) {
    int row = 0;
    int col = n-1;
    // start from right-up corner
    while (row < m && col >= 0) {
        if (matrix[row][col] == element)
            return true;
        else if (matrix[row][col] > element)
            col--;    
        else
            row++;    
    }    
    return false;
}

int main() {
    int matrix[5][5] = {{1, 3, 5, 8}, {2, 4, 7, 9}, {6, 10, 11, 13}};
    cout << search(matrix, 3, 4, 7) << endl;
    cout << search(matrix, 3, 4, 12) << endl;
    return 0;
}
