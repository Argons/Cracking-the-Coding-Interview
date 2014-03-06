#include <iostream>
#include <cstdlib>
using namespace std;

// Write a method to generate a random number between 1 and 7, given a method
// that generates a random number between 1 and 5.
// (i.e., implement rand7() using rand5())

int rand5() {
    return rand()%5 + 1;
}

int rand7() {
    int ret = 0;
    for (int i = 0; i < 7; i++) {
        ret += rand5();
    }
    return ret % 7 + 1;
}

int Rand7() {
    while (true) {            
        int num = 5 * (rand5() - 1) + (rand5() - 1);
        if (num < 21) 
            return (num % 7 + 1);
    }
}

int main() {
    int record[7] = {0};
    for (int i = 0; i < 20000; i++) {
        record[Rand7()-1]++;
    }
    for (int i = 0; i < 7; i++) {
        cout << i+1 << "  " << record[i] << endl;
    }
    return 0;
}
