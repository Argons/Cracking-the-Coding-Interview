#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// Design a method to find the frequency of occurrences of any given word in a book.

string lower(string str) {
    for (int i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

map<string, int> setDictTable(vector<string> &book) {
    map<string, int> dict;
    for (int i = 0; i < book.size(); i++) {
        string str = lower(book[i]);
        if (dict.find(str) == dict.end()) {
            dict.insert(make_pair<string, int>(str, 1));
        } else {
            dict[str] += 1;
        }
    }
    return dict;
}

int wordFrequency(string word, vector<string> &book) {
    map<string, int> dict = setDictTable(book);
    if (word.empty() || dict.empty())
        return -1;
    if (dict.find(lower(word)) != dict.end())
        return dict[lower(word)];
    return 0;
}

int main() {
    string word;
    vector<string> book;
    ifstream wordfile("The Call Of The Wild.txt");
    while (wordfile >> word) {
        book.push_back(word);
    }
    cin >> word;
    cout << "word frequency: " << wordFrequency(word, book) << endl;
    return 0;
}
