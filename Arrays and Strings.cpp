#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <cstdlib>
using namespace std;

/// 1.1  time:O(n) space:O(n)
bool testUniqueChars(const string &str)
{
    int len = str.length();
    bool ASCIITable[256] = { false };
    for (int i = 0; i < len; i++) {
        int index = str[i];
        if (ASCIITable[index])
            return false; // duplicate found.
        ASCIITable[index] = true;
    }
    return true;
}


/// 1.2 -reverse a string
void reverseString(char str[])
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
        len++;
    int i = --len;
    // swap chars of symmetric indexes until reach the midst of string.
    while (i - (len-i) > 1) {
        swap(str[i], str[len-i]);
        i--;
    }
}


/// 1.3 -remove dupilcate characters from string.
void removeDuplicates(char str[])
{
    if (str == NULL)
        return;
    bitset<256> ASCIITable;
    ASCIITable.reset();

    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
        len++;
    int new_len = 1;
    ASCIITable.set(str[0]);
    for (int i = 1; i < len; i++) {
        int idx = str[i];
        if (!ASCIITable[idx]) {
            str[new_len++] = str[i];
            ASCIITable.set(idx);
        }
    }
    str[new_len] = '\0';
}
void test()
{
    char str[5][10] = {"abcd", "aaaa", "", "aaabbb", "abababa"};
    for (int i = 0; i < 5; i++) {
        cout<<str[i]<<"\t";
        RemoveDuplicates(str[i]);
        cout<<str[i]<<endl;
    }
}


/// 1.4 -decide whether two strings are anagrams.
int compare(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}
bool testAnagrams(char a[], char b[])
{
    int a_len = 0, b_len = 0;
    for (int i = 0; a[i] != '\0'; i++)
        a_len++;
    for (int i = 0; b[i] != '\0'; i++)
        b_len++;
        
    if (a_len != b_len)
        return false;
    qsort (a, a_len, sizeof(char), compare);
    qsort (b, b_len, sizeof(char), compare);
    for (int i = 0; i < a_len; i++)
        if (a[i] != b[i])
            return false;
            
    return true;
}


/// 1.5 -replace all spaces in a string with '%20'.
void replaceSpaces(char str[])
{
    int len = 0, count_spaces = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            count_spaces++;
        len++;
    }
    int new_len = len + count_spaces * 2;
    str[new_len] = '\0';
    // traverse backwards, otherwise the characters unvisited might 
    // have been overwritten already.
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[new_len-1] = '0';
            str[new_len-2] = '2';
            str[new_len-3] = '%';
            new_len -= 3;
        } else {
            str[new_len-1] = str[i];
            new_len--;
        }
    }
}


/// 1.6 -rotate an image in place, which is represented by an N*N matrix, by 90 degrees.
void rotateMatrix(int **matrix, int n)
{
    // rotate by layers, altogether n/2 layers in the matrix.
    for (int i = 0; i < n / 2; i++) {
        int start = i;
        int end = n - 1 - i;
        for (int j = start; j < end; j++) {
            int top = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];         // left -> top
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j]; // bottom -> left
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i]; // right -> bottom
            matrix[j][n-1-i] = top;                  // top -> right
        }
    }
}


/// 1.7 -if M[i][j]=0, set its entire row and column to 0.
void setZeros(int **matrix, int row_num, int col_num)
{
    bool row[row_num];
    bool col[col_num];
    for (int i = 0; i < col_num; i++)
        col[i] = false;
    for (int i = 0; i < row_num; i++) {
        row[i] = false;
        for (int j = 0; j < col_num; j++) {
            if (matrix[i][j] == 0) {
            // mark the rows and columns that contain 0.
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < row_num; i++)
        for (int j = 0; j < col_num; j++)
            if (row[i] == true || col[j] == true)
                matrix[i][j] = 0;

}


/// 1.8 -call isSubstring() once to determine rotation of a string.
bool isSubstring(string substring, string str)
{
    if (str.find(substring) == -1)
        return false;
    return true;
}
bool isRotation(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    string cat_two_str1 = str1 + str1;
    return isSubstring(str2, cat_two_str1);
}
