# include <iostream>
# include <vector>
# include <stack>
using namespace std;

// Imagine a (literal) stack of plates. If the stack gets too high, 
// it might topple. Therefore, in real life, we would likely start 
// a new stack when the previous stack exceeds some threshold.

// Implement a data structure SetOfStacks that mimics this. SetOf-
// Stacks should be composed of several stacks, and should create a 
// new stack once the previous one exceeds capacity.

// SetOfStacks.push() and SetOfStacks.pop() should behave identically
// to a single stack (that is, pop() should return the same values as
// it would if there were just a single stack).

// Implement a function popAt(int index) which performs a pop operation
// on a specific sub-stack.

struct SetOfStacks {
    vector<stack<int> > stacks;
    int stackSize;
    SetOfStacks(int size) {
        stackSize = size;
        stacks.push_back(stack<int>());
    }
    bool isEmpty() { return stacks[0].empty(); }
    void push(int item) {
        if ((*stacks.rbegin()).size() == stackSize) {
            stacks.push_back(stack<int>());
        }
        (*stacks.rbegin()).push(item);
    }
    int pop() {
        if ((*stacks.rbegin()).empty()) {
            if (stacks.empty())
                return -1;
            stacks.pop_back();
        }
        int item = (*stacks.rbegin()).top();
        (*stacks.rbegin()).pop();
        return item;
    }
    int popAt(int index) {
        int item = stacks[index].top();
        stacks[index].pop();
        return item;
    }
};

int main() {
    SetOfStacks S(2);
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    cout << S.pop() << endl;
    cout << S.pop() << endl;
    cout << S.popAt(0) << endl;
    return 0;
}
