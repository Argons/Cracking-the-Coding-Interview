# include <iostream>
# include <vector>
# include <string>
# include <cmath>
using namespace std;

// Write an algorithm to print all ways of arranging eight queens on a chess
// board so that none of them share the same row, column or diagonal.


vector<string> getBoard(vector<int> &queenPos, int n) {
    vector<string> board(n, string(n, '.'));
    for (int i = 0; i < n; i++) {
        board[i][queenPos[i]] = 'Q';
    }
    return board;
}

bool check(vector<int> &queenPos, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (queenPos[i] == col)
            return false;
        if (abs(col-queenPos[i]) == abs(row-i))
            return false;
    }
    return true;
}

void putQueen(vector<int> &queenPos, int row, int n, 
              vector<vector<string> > &result) {
    if (row == n) {
        result.push_back(getBoard(queenPos, n));
        return;
    }
    for (int i = 0; i < n; i++) {
        if (check(queenPos, row, i, n)) {
            queenPos[row] = i;
            putQueen(queenPos, row+1, n, result);
            queenPos[row] = -1;
        }
    }
}

vector<vector<string> > nQueens(int n) {
    vector<int> queenPos(n, -1);
    vector<vector<string> > result;
    putQueen(queenPos, 0, n, result);
    return result;
}


int main() {
    vector<vector<string> > result = nQueens(8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}
