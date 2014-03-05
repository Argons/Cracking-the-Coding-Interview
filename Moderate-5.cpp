#include <iostream>
#include <vector>
#include <string>
using namespace std;

// The Game of Master Mind is played as follows:    
// The computer has four slots containing balls that are red (R), yellow (Y), 
// green (G) or blue (B). 
// For example, the computer might have RGGB (e.g., Slot #1 is red, Slots #2 
// and #3 are green, Slot #4 is blue).
// You, the user, are trying to guess the solution. You might, for example, 
// guess YRGB. When you guess the correct color for the correct slot, you get 
// a “hit”. If you guess a color that exist but is in the wrong slot, you get
// a “pseudo-hit”. For example, the guess YRGB has 2 hits and one pseudo hit.
// For each guess, you are told the number of hits and pseudo-hits.
// Write a method that, given a guess and a solution, returns the number of 
// hits and pseudo hits.

vector<int> checkHits(string solution, string guess) {
    vector<int> ret(2, 0);
    for (int i = 0; i < solution.size(); i++) {
        char t = guess[i];
        if (solution[i] == guess[i]) {
            ret[0] += 1;
        } else if (solution.find(t) != -1) {
            ret[1] += 1;
        }
    }
    return ret;
}

int main() {
    string solution = "RGGB";
    string guess = "YRGB";
    vector<int> ret = checkHits(solution, guess);
    cout << "hit: " << ret[0] << endl;
    cout << "pseudo-hit: " << ret[1] << endl;
    return 0;
}
