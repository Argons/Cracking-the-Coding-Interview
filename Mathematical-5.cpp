#include <iostream>
using namespace std;

// Given two squares on a two dimensional plane, find a line that would cut 
// these two squares in half. 

struct square {
    double top;
    double bottom;
    double left;
    double right;
    square(double t, double b, double l, double r) : top(t), bottom(b), 
                                                     left(l), right(r) {}
};

struct point {
    double x;
    double y;
    point(double a, double b) : x(a), y(b) {}
};

struct line {
    double slope;
    double yIntercept;
    line(double a, double b) : slope(a), yIntercept(b) {}
};

line findLine(square a, square b) {
    // the line that separates a square in half will pass its center.
    point mid_a((a.left+a.right)/2, (a.top+a.bottom)/2);
    point mid_b((b.left+b.right)/2, (b.top+b.bottom)/2);
    double slope = (mid_a.y-mid_b.y) / (mid_a.x-mid_b.x);
    double intercept = mid_a.y - mid_a.x * slope;
    line cut(slope, intercept);
    return cut;
}

int main() {
    square a(5.0, 1.0, 2.0, 6.0);
    square b(3.0, 1.0, -1.0, 1.0);
    line cut = findLine(a, b);
    cout << "cut line: " << "y = " << cut.slope << " * x + " << cut.yIntercept
         << endl;
    return 0;
}
