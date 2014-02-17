# include <iostream>
using namespace std;

// Write a method to replace all spaces in a string with ‘%20’.

void replaceSpaces(char str[]) {
    int len = 0, count_spaces = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            count_spaces++;
        len++;
    }
    int new_len = len + count_spaces * 2;
    str[new_len] = '\0';
    // traverse backwards, otherwise the characters 
    // unvisited might have been overwritten.
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[new_len-1] = '0';
            str[new_len-2] = '2';
            str[new_len-3] = '%';
            new_len -= 3;
        }
        else {
            str[new_len-1] = str[i];
            new_len--;
        }
    }
}
