# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

// Write a method that returns all subsets of a set.

void getSubsets(vector<int> &set, int start, vector<vector<int> > &result, 
                vector<int> &item) {
    result.push_back(item);
    if (start >= set.size())
        return;
    for (int i = start; i < set.size(); i++) {
        if (i != start && set[i] == set[i-1])
            continue;
        item.push_back(set[i]);
        getSubsets(set, i+1, result, item);
        item.pop_back();
    }

}

vector<vector<int> > subsets_II(vector<int> &set) {
    vector<vector<int> > result;
    vector<int> item;
    sort(set.begin(), set.end());
    getSubsets(set, 0, result, item);
    return result;
}

// iterative
vector<vector<int> > subsets(vector<int> &set) {
    vector<vector<int> > result(1);
    for (int i = 0; i < set.size(); i++) {
        int j = result.size();
        while (j > 0) {
            j--;
            result.push_back(result[j]);
            result.back().push_back(set[i]);
        } 
    }
    return result;
}


int main() {
    vector<int> set;
    set.push_back(1);
    set.push_back(2);
    set.push_back(3);
    vector<vector<int> > result = subsets_II(set);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
