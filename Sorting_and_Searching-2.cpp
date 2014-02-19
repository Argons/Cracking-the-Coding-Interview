# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;

// Write a method to sort an array of strings so that 
// all the anagrams are next to each other.
bool isAnagram(string a, string b) {
    if (a.length() != b.length())
        return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}
void sortStrings(vector<string> &v) {
    sort(v.begin(), v.end()); 
    int len = v.size(); 

    for(int i = 0; i < len ;i++){ 
        for(int j = i + 1; j < len; j++){ 
            if(isAnagram(v[i], v[j])){ 
                swap(v[++i], v[j]);
            } 
        } 
    } 
}

int main() {
    string str[10] = {"as", "when", "abc", "sa", "f", "cba", "at", "whne", "f"};
    vector<string> array;
    array.assign(str, str+9);
    sortStrings(array);
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    return 0;
}
