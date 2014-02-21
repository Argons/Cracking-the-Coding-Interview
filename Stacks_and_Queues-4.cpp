# include <iostream>
using namespace std;

// In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of
// different sizes which can slide onto any tower. The puzzle starts with disks 
// sorted in ascending order of size from top to bottom.
// (e.g., each disk sits on top of an even larger one)

// You have the following constraints:  
// (A) Only one disk can be moved at a time.
// (B) A disk is slid off the top of one rod onto the next rod.
// (C) A disk can only be placed on top of a larger disk.
// Write a program to move the disks from the first rod to the last using Stacks.

int solveHanoiTower(int n) {
    // hanoi tower of level N: (2^n - 1) steps.
    if (n == 1)
        return 1;
    return 1 + 2 * solveHanoiTower(n-1);
}

int main() {
    cout << "After " << solveHanoiTower(7) << " Steps." << endl;
    return 0;
}
