#include <iostream>
using namespace std;

// You have a basketball hoop and someone says that you can play 1 of 2 games.
// Game #1: You get one shot to make the hoop.
// Game #2: You get three shots and you have to make 2 of 3 shots.
// If p is the probability of making a particular shot, for which values of p 
// should you pick one game or the other?

int main() {
    double p;
    cin >> p;
    double p1 = p;
    double p2 = 3*(1-p)*p*p + p*p*p;
    cout << "pick Game " << (p1 > p2 ? 1 : 2) << endl;
    return 0;
}
