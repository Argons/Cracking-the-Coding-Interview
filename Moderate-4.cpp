#include <iostream>
using namespace std;

// Write a method which finds the maximum of two numbers. You should not use 
// if-else or any other comparison operator.
// EXAMPLE
// Input: 5, 10
// Output: 10

int getMax(int a, int b) {
    int c = a - b;
    int k = (c >> 31) & 1;  // k = 1 if c is negative.
    int max = a - k * c;
    return max;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << "the maximum: " << getMax(a, b) << endl;
    return 0;
}
