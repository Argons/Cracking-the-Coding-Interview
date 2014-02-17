# include <iostream>
# include <algorithm>
using namespace std;

// Write code to reverse a C-Style String. (C-String means that “abcd” 
// is represented as five characters, including the null character.

void ReverseString(char str[]) {
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
        len++;
    int i = --len;
    // exchange chars with symmetric indexes until the middle of string.
    while (i - (len-i) > 1) {
        swap(str[i], str[len-i]);
        i--;
    }
}
