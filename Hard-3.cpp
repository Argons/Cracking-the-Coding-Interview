#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Write a method to randomly generate a set of m integers from an array of size n.
// Each element must have equal probability of being chosen.

vector<int> randM(vector<int> &array, int m) {
    vector<int> subset;
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        int index = rand() % (array.size()-i) + i;
        swap(array[i], array[index]);
        subset.push_back(array[i]);
    }
    return subset;
}

int main() {
    vector<int> array;
    int a[10] = {3, 1, 5, 8, 0, 2, 7, 4, 9, 6};
    array.assign(a, a+10);
    int m;
    cin >> m;
    vector<int> ret = randM(array, m);
    for (int i = 0; i < m; i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}
