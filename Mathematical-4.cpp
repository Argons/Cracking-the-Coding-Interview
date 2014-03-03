#include <iostream>
using namespace std;

// Write a method to implement *, - , / operations. 
// You should use only the + operator.

int negative(int a) {
    int sign = a < 0 ? 1 : -1;
    int ret = 0;
    while (a) {
        ret += sign;
        a += sign;
    }
    return ret;
}

int Abs(int a) {
    if (a < 0) {
        a = negative(a);
    }
    return a;
}

bool checkSign(int a, int b) {
    return (a < 0 && b < 0) || (a > 0 && b > 0);
}

int Multiply(int a, int b) {
    int ret = 0;
    if (b > 0) {
        b = negative(b);
    } else {
        a = negative(a);
    }
    while (b) {
        ret += a;
        b++;
    }
    return ret;
}

int Minus(int a, int b) {
    return a + negative(b);
}

int Divide(int a, int b) {
    int ret = 0;
    int sign = checkSign(a, b);
    if (b == 0) {
        throw "Divide by zero exception";
    }
    a = Abs(a);
    b = Abs(b);
    while (a > b) {
        a = Minus(a, b);
        ret++;
    }
    if (!sign) {
        ret = negative(ret+1);
    }
    return ret;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << "a * b = " << Multiply(a, b) << endl;
    cout << "a - b = " << Minus(a, b) << endl;
    cout << "a / b = " << Divide(a, b) << endl;
    return 0;
}
