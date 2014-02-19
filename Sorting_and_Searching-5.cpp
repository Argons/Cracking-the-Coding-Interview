# include <iostream>
# include <string>
# include <vector>
using namespace std;

// Given a sorted array of strings which is interspersed with empty strings,
// write a method to find the location of a given string.

// Example: 
//   find “ball” in [“at”, “”, “”, “”, “ball”, “”, “”, “car”, “”, “”, “dad”, “”, “”] will return 4.
// Example: 
//   find “ballcar” in [“at”, “”, “”, “”, “”, “ball”, “car”, “”, “”, “dad”, “”, “”] will return -1.

int findString(vector<string> &strs, const string &s) {
    if (strs.empty() || s.empty())
        return -1;
    if (s == "") {
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i] == "")
                return i;
        }
        return -1;
    }

    int start = 0, end = strs.size()-1, mid;
    while (start <= end) {
        // make sure the end is not "".
        while (start <= end && strs[end] == "") {
            end--;
        }
        mid = (start+end) >> 1;
        while (strs[mid] == "") {
            mid++;
        }
        if (strs[mid] == s)
            return mid;
        else {
            if (strs[mid] < s)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}


int main() {
    string str[20] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    vector<string> strs;
    strs.assign(str, str+13);
    cout << findString(strs, "ball") << endl;
    cout << findString(strs, "ballcar") << endl;
    return 0;
}
