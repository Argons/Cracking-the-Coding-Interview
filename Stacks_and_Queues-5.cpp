# include <iostream>
# include <stack>
using namespace std;

// Implement a MyQueue class which implements a queue using two stacks.

class MyQueue {
private:
    stack<int> s1, s2;
    int queueSize;

public:
    MyQueue() { queueSize = s1.size() + s2.size(); }

    int peek() {
        if (!s2.empty())
            return s2.top();

        // push item into stack s1, when in need of the top item, 
        // pop all items into stack s2, and return the top of s2.
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }

    void enqueue(int item) {
        s1.push(item);
    }

    int dequeue() {
        int item;
        if (!s2.empty()) {
            item = s2.top();
            s2.pop();
            return item;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        item = s2.top();
        s2.pop();
        return item;
    }
};

int main() {
    return 0;
}
