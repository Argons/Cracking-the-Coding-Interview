#include <iostream>
#include <cmath>
using namespace std;

// There are three ants on different vertices of a triangle. What is the 
// probability of collision (between any two or all of them) if they start 
// walking on the sides of the triangle? Similarly find the probability of 
// collision with ‘n’ ants on an ‘n’ vertex polygon.


int main() {
    double p = (8.0-2.0) / 8.0;  // 8 possibilities, 2 avoid collision.
    cout << "probability of collision on triangle: " << p << endl;
    int n;
    cin >> n;
    p = 1 - 2.0 / pow(2, n);
    cout << "probability of collision on N vertex polygon: " << p << endl;
    return 0;
}
