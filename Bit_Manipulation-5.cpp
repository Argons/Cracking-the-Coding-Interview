# include <iostream>
using namespace std;

// Write a function to determine the number of bits required to 
// convert integer A to integer B.   
// Input: 31, 14
// Output: 2

int bitSwapRequired(int a, int b) {
    int XOR = a ^ b;  // use XOR to record the different bits of a and b.
    int count = 0;
    while (XOR) {
        count += XOR & 1;
        XOR >>= 1;
    }
    return count;
}
