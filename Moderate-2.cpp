#include <iostream>
#include <vector>
using namespace std;

// Design an algorithm to figure out if someone has won in a game of tic-tac-toe.

enum player {empty, black, blue};

player getWinner(vector<vector<player> > &board) {
    int row = board.size();
    int col = board[0].size();

    // check row, col, cross for 3 consecutive items of the same player.
    for (int i = 1; i < row-1; i++) {
        for (int j = 1; j < col-1; j++) {
            if (board[i][j] != empty) {
                if ((board[i][j] == board[i-1][j] &&
                     board[i][j] == board[i+1][j])   ||
                    (board[i][j] == board[i][j-1] &&
                     board[i][j] == board[i][j+1])   ||
                    (board[i][j] == board[i-1][j-1] &&
                     board[i][j] == board[i+1][j+1]) ||
                    (board[i][j] == board[i-1][j+1] &&
                     board[i][j] == board[i+1][j-1])) {
                    return board[i][j];
                }
            }
        }
    }
}

int main() {
    vector<player> row(3, empty);
    vector<vector<player> > board(3, row);
    board[0][2] = blue;
    board[2][0] = blue;
    board[1][1] = blue;
    board[0][1] = black;
    board[2][1] = black;
    board[2][2] = black;
    cout << "player " << getWinner(board) << " has won." << endl;
    return 0;
}
