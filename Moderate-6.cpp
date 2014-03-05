#include <iostream>
using namespace std;

// Given an integer between 0 and 999,999, print an English phrase that 
// describes the integer.(eg, “One Thousand, Two Hundred and Thirty Four”)

string dict1[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string dict2[10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string numToString(int num) {
    if (num / 1000) {
        if (num % 1000 == 0)
            return numToString(num/1000) + " thousand";
        if ((num%1000) / 100)
            return numToString(num/1000) + " thousand, " + numToString(num%1000);
        return numToString(num/1000) + " thousand and " + numToString(num%1000);
    }
    if (num / 100) {
        if (num % 100 == 0)
            return numToString(num/100) + " hundred";
        return numToString(num/100) + " hundred and " + numToString(num%100);
    }
    if (num / 10) {
        if (num % 10 == 0)
            return dict2[num/10];
        return dict2[num/10] + " " +dict1[num%10];
    }
    return dict1[num%10];
}

int main() {
    int num;
    cin >> num;
    cout << numToString(num) << endl;
    return 0;
}
