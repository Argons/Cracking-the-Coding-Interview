# include <iostream>
# include <string>
using namespace std;

// Implement an algorithm to determine if a string has all unique characters.

bool testUniqueChars(const string &str) {
    int len = str.length();
    bool asciiTable[256] = { false };
    for (int i = 0; i < len; i++) {
        int index = str[i];
        if (asciiTable[index])
            return false;  // duplicate found
        asciiTable[index] = true;
    }
    return true;
}
