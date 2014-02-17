# include <iostream>
# include <bitset>
using namespace std;

// Design an algorithm and write code to remove the duplicate characters in 
// a string without using any additional buffer.

// NOTE: One or two additional variables are fine. 
// An extra copy of the array is not.

void removeDuplicates(char str[]) {
    if (str == NULL)
        return;
    bitset<256> asciiTable;
    asciiTable.reset();

    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
        len++;
    int new_len = 1;
    asciiTable.set(str[0]);
    for (int i = 1; i < len; i++) {
        int idx = str[i];
        if (!asciiTable[idx]) {
            str[new_len++] = str[i];
            asciiTable.set(idx);
        }
    }
    str[new_len] = '\0';
}

void test() {
    char str[5][10] = {"abcd", "aaaa", "", "aaabbb", "abababa"};
    for (int i = 0; i < 5; i++) {
        cout << str[i] << "\t";
        removeDuplicates(str[i]);
        cout << str[i] << endl;
    }
}

int main() {
    test();
    return 0;
}
