# include <iostream>
# include <vector>
# include <algorithm>
# include <utility>
using namespace std;

// A circus is designing a tower routine consisting of people standing atop one
// another’s shoulders. For practical and aesthetic reasons, each person must be
// both shorter and lighter than the person below him or her. 

// Given the heights and weights of each person in the circus, write a method to
// compute the largest possible number of people in such a tower.

// EXAMPLE:
// Input (ht, wt): 
//   (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)
// Output: The longest tower is length 6 and includes from top to bottom:
//   (56, 90) (60,95) (65,100) (68,110) (70,150) (75,190)

bool compare(pair<int, int> pa, pair<int, int> pb) {
    if (pa.first < pb.first)
        return true;
    if (pa.first == pb.first)
        return pa.second < pb.second;
    return false;
}

int maxNum(vector<pair<int, int> > profile, int start) {
    if (start >= profile.size())
        return 0;
    int num = 1;
    int weight = profile[start].second;
    for (int i = start; i < profile.size(); i++) {
        if (weight < profile[i].second) {
            num++;
            weight = profile[i].second;
        }
    }
    return num;
}
int maxNum(vector<pair<int, int> > profile) {
    if (profile.empty())
        return 0;
    sort(profile.begin(), profile.end(), compare);
    int maxPeople = 0;
    vector<int> result(profile.size(), 0);
    result[0] = maxNum(profile, 0);
    for (int i = 0; i < profile.size()-1; i++) {
        if (profile[i].second > profile[i+1].second) {
            result[i+1] = maxNum(profile, i+1);  // restart from unfit ones
        }
    }
    for (int i = 0; i < result.size(); i++) {
        maxPeople = max(maxPeople, result[i]);
    }
    return maxPeople;
}

int main() {
    int num[10][2] = {{65, 100}, {70, 150}, {56, 90}, {75, 140}, {60, 95}, {68, 110}};
    vector<pair<int, int> > profile;
    for (int i = 0; i < 6; i++) {
        profile.push_back(make_pair(num[i][0], num[i][1]));
    }
    cout << maxNum(profile) << endl;
    return 0;
}
