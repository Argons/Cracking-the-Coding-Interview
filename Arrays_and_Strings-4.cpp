# include <iostream>
# include <cstdlib>
using namespace std;

int compare(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}
bool testAnagrams(char a[], char b[]) {
    int a_len = 0, b_len = 0;
    for (int i = 0; a[i] != '\0'; i++) 
        a_len++;
    for (int i = 0; b[i] != '\0'; i++) 
        b_len++;
    if (a_len != b_len)
        return false;
    qsort(a, a_len, sizeof(char), compare);
    qsort(b, b_len, sizeof(char), compare);
    for (int i = 0; i < a_len; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

int main() {

}
