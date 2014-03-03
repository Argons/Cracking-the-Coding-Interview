#include <iostream>
#include <cmath>
using namespace std;

// Given two lines on a Cartesian plane, determine whether the two lines would
// intersect.

struct line {
    static const float epsilon = 0.000001;
    float slope;
    float yIntercept;
    line(float a, float b) : slope(a), yIntercept(b) {}
};

bool checkIntersect(line a, line b) {
   return fabs(a.slope-b.slope) > a.epsilon || 
          fabs(a.yIntercept-b.yIntercept) < a.epsilon;
}

int main() {
    line a(3.0, 4.0);
    line b(4.0, 3.0);
    line c(3.0, 5.0);
    cout << checkIntersect(a, b) << endl;
    cout << checkIntersect(a, c) << endl;
    return 0;
}
