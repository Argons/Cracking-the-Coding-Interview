# include <iostream>
# include <stack>
using namespace std;

// Write a program to sort a stack in ascending order. You should not make any 
// assumptions about how the stack is implemented. The following are the only 
// functions that should be used to write this program: 
// push | pop | top | isEmpty.

void sortStack(stack<int> &s) {
    stack<int> ret;
    // time complexity: O(N*N).
    while (!s.empty()) {
        int tmp = s.top();
        s.pop();
        while (!ret.empty() && ret.top() > tmp) {
            s.push(ret.top());
            ret.pop();
        }
        ret.push(tmp);
    }
    s = ret;
}

int main() {
    stack<int> s;
    s.push(4);
    s.push(7);
    s.push(2);
    s.push(8);
    s.push(0);
    s.push(5);
    sortStack(s);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;    
}
