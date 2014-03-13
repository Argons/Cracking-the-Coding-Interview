#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <cassert>
using namespace std;

// Numbers are randomly generated and passed to a method. Write a program 
// to find and maintain the median value as new values are generated.

// max heap for the values below the median;
// min heap for the values above the median;
// median is the top of max heap.
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int> > minHeap;

void addNumber(int random) {
    if (maxHeap.size() <= minHeap.size()) {
        if (!minHeap.empty() && random > minHeap.top()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(random);
        } else {
            maxHeap.push(random);
        }
    } else {
        if (random < maxHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(random);
        } else {
            minHeap.push(random);
        }
    }
}

double median() {
    assert(maxHeap.size());
    if (maxHeap.size() == minHeap.size())
        return (maxHeap.top() + minHeap.top()) / 2.0;
    else
        return maxHeap.top();
}


int main() {
    int n;
    while (cin >> n) {
        addNumber(n);
        cout << median() << endl;
    }
    return 0;
}
