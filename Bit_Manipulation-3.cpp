#include <iostream>
using namespace std;

// Given an integer, print the next smallest and next largest number that 
// have the same number of 1 bits in their binary representation.

int nextSmallest(int num) {
    int bit = 0, count = 0;
    int ret = num, pre = -1, cur = num & 1;
    while (num) {
        if (cur == 1) {
            count++;
            if (pre == 0) {
                // the bits on the right of cur are not all 0.
                if (count > 1) {  
                    ret = (num-1) << bit;
                    ret += ((1 << count) - 1) << (bit-count);
                }
                else {
                    ret |= (1 << (bit-1));
                    ret &= ~(1 << bit);
                }
                return ret;
            }
        }
        pre = cur;
        num >>= 1;
        cur = num & 1;
        bit++;
    }
    return ret;
}

int nextLargest(int num) {
    if (num == 0)
        return 0;
    int ret = num, bit = 0, count = 0;
    int pre = -1, cur = num & 1;
    while (num) {
        if (cur == 1) {
            count++;
        }
        if (cur == 0 && pre == 1) {
            ret = (num+1) << bit;
            ret += (1 << count-1) - 1;
            return ret;
        }
        pre = cur;
        num >>= 1;
        cur = num & 1;
        bit++;
    }
    ret = (1 << bit) + (1 << count-1) - 1;
    return ret;
}

int main() {
    int num;
    cin >> num;
    cout << "next smallest number: " << nextSmallest(num) << endl;
    cout << "next largest number: " << nextLargest(num) << endl;
    return 0;
}
