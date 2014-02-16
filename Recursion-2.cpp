# include <iostream>
using namespace std;

// Imagine a robot sitting on the upper left hand corner of an NxN grid. The robot can
// only move in two directions: right and down. How many possible paths are there for
// the robot?

// FOLLOW UP
// Imagine certain squares are “off limits”, such that the robot can not step on them.
// Design an algorithm to get all possible paths for the robot.

int countPaths(int x, int y) {
    if (x < 1 || y < 1)
        return 0;
    if (x == 1 || y == 1)
        return 1;     
    return countPaths(x-1, y) + countPaths(x, y-1);
}

// iterative version
int countPaths(int n) {
    if (n < 1)  
        return 0;
    int paths[n][n];
    paths[0][0] = 1;
    for (int i = 0; i < n; i++) {
        paths[0][i] = 1;
        paths[i][0] = 1;
    }
    int result = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            paths[i][j] = paths[i-1][j] + paths[i][j-1];
        }
    }
    return paths[n-1][n-1];
}

int main() {
    int n;
    cin >> n;
    cout << countPaths(n, n) << endl;
    cout << countPaths(n) << endl;
    return 0;
}
