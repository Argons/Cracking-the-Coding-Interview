# include <iostream>
using namespace std;

// Write an algorithm such that if an element in an MxN matrix is 0, 
// its entire row and column is set to 0.

void setZeros(int **matrix, int row_num, int col_num) {
    bool row[row_num];
    bool col[col_num];
    for (int i = 0; i < col_num; i++)
        col[i] = false;
    for (int i = 0; i < row_num; i++) {
        row[i] = false;
        for (int j = 0; j < col_num; j++) {
            if (matrix[i][j] == 0) {
                // mark the rows and columns that contain 0.
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < row_num; i++)
        for (int j = 0; j < col_num; j++)
            if (row[i] == true || col[j] == true)
                matrix[i][j] = 0;

}

