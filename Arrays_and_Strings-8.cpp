# include <iostream>
# include <string>
using namespace std;

// Assume you have a method isSubstring which checks if one word is a substring
// of another. 
// Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 
// using only one call to isSubstring (i.e., “waterbottle” is a rotation of 
// “erbottlewat”)

bool isSubstring(string substring, string str) {
    if (str.find(substring) == -1)
        return false;
    return true;
}

bool isRotation(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;
    string cat2str1 = str1 + str1;
    return isSubstring(str2, cat2str1);
}
