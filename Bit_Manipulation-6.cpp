# include <iostream>
using namespace std;

// Write a program to swap odd and even bits in an integer with as 
// few instructions as possible.
// e.g., bit 0 and 1 are swapped, bit 2 and bit 3 are swapped, etc.

int iwapOddAndEvenBits(int num) {
    // &0xA (= 1010), record the odd  bits;
    // &0x5 (= 0101), record the even bits;
    // 'int' has 32 bits, i.e. 8 bits for hex.
    return ( ((num & 0xAAAAAAAA) >> 1) | ((num & 0x55555555) << 1) );
}
