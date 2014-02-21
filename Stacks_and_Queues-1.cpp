# include <iostream>
using namespace std;

// Describe how you could use a single array to implement three stacks.

const int stackSize = 100;
int *array = new int[stackSize * 3];
int stackIndicator[3] = {0, 0, 0};

void push(int stackIdx, int value) {
    int index = stackIdx * stackSize + stackIndicator[stackIdx];
    array[++index] = value;
    stackIndicator[stackIdx]++;
}

int pop(int stackIdx) {
    int index = stackIdx * stackSize + stackIndicator[stackIdx];
    stackIndicator[stackIdx]--;
    return array[index];
}

bool isEmpty(int stackIdx) {
    return stackIndicator[stackIdx]; 
}

int main() {
    return 0;
}
