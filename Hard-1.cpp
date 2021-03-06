#include <iostream>
using namespace std;

// Write a function that adds two numbers. You should not use + or any 
// arithmetic operators.

int add(int a, int b) {
    if (b == 0)
        return a;
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return add(sum, carry);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << add(a, b) << endl;
    return 0;
}
