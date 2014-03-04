#include <iostream>
#include <algorithm>
using namespace std;

// Write an algorithm which computes the number of trailing zeros in n factorial.

int countZero(int n) {
    int N5 = 0;
    int factor5 = 5;
    while (n >= factor5) {
        N5 += n / factor5;
        factor5 *= 5;
    }
    return N5;
}

int main() {
    int n;
    cin >> n;
    cout << countZero(n) << endl;
    return 0;
}
