#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string printBinary(string num) {
    int dot = num.find('.');
    int intPart = atoi(num.substr(0, dot).c_str());
    double decPart = atof(num.substr(dot, num.length()-dot).c_str());
    string intStr = "", decStr = "";

    while (intPart > 0) {
        if (intPart & 1) {
            intStr = "1" + intStr;
        }
        else {
            intStr = "0" + intStr;
        }
        intPart >>= 1;
    }
    while (decPart > 0) {
        if (decStr.length() > 32) 
            return "ERROR";

        decPart *= 2;
        if (decPart >= 1) {
            decStr += "1";
            decPart -= 1;
        }
        else {
            decStr += "0";
        }
    }
    string ret = intStr + "." + decStr;
    return ret;
}

int main() {
    string num;
    cin >> num;
    cout << printBinary(num) <<endl;
    return 0;
}
