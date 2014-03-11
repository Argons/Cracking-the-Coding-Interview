#include <iostream>
using namespace std;

// Write a method to count the number of 2s between 0 and n.

int count2(int n, int power) {    
    int ret;
    if (power == 1)
        return (n >= 2 ? 1 : 0);
    if (n / power > 2) {
        ret = count2(power-1, power/10) * (n/power) + power + 
              count2(n%power, power/10);
    } else if (n / power == 2) {
        ret = count2(power-1, power/10) * 2 + (n%power+1) + 
              count2(n%power, power/10);
    } else {
        ret = count2(power-1, power/10) + 
              count2(n%power, power/10);
    }
    return ret;
}

int count2(int num) {
    int power = 1;
    while (power * 10 < num) {
        power *= 10;
    }
    return count2(num, power);
}

int main() {
    int n;
    cin >> n;
    cout << count2(n) << endl;
    return 0;
}
