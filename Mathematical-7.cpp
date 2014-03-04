#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// Design an algorithm to find the kth number such that the only prime factors 
// are 3, 5, and 7.

int kthNumber(int k) {
    if (k <= 0) 
        return 0;
    int ret = 1;
    queue<int> Q3, Q5, Q7;
    Q3.push(3);
    Q5.push(5);
    Q7.push(7);

    for (int i = 0; i < k-1; i++) {
        ret = min(Q3.front(), min(Q5.front(), Q7.front()));
        if (ret == Q7.front()) {
            Q7.pop();
        } else {
            if (ret == Q5.front()) {
                Q5.pop();
            } else {
                Q3.pop();
                Q3.push(ret * 3);
            }
            // don't need to append x*3 and x*5 to all lists because
            // they will already be found in another list.
            Q5.push(ret * 5);
        }
        Q7.push(ret * 7);
    }
    return ret;
}

int main() {
    int k;
    cin >> k;
    cout << kthNumber(k) << endl;
    return 0;
}
