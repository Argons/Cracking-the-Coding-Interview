#include <iostream>
using namespace std;

// Write a function to swap a number in place without temporary variables.

void swap(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() {
    int a, b;
    cin >> a >> b;
    swap(a, b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    return 0;
}
