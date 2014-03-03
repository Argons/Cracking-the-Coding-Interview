#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

// Given a two dimensional graph with points on it, find a line which passes 
// the most number of points.

const double epsilon = 0.000001;

struct point {
    double x;
    double y;
    point(double a, double b) : x(a), y(b) {}
};

struct line {
    double slope;
    double yIntercept;
    line(double a, double b) : slope(a), yIntercept(b) {}
    bool operator== (const line& b) const {
        return (fabs(slope-b.slope) < epsilon) && 
               (fabs(yIntercept-b.yIntercept) < epsilon);
    }
    bool operator< (const line& b) const {
        return slope < b.slope;
    }
};

line connectPoints(point a, point b) {
    double slope = (a.y-b.y) / (a.x-b.x);
    double intercept = a.y - a.x * slope;
    return line(slope, intercept);
}

line findLine(vector<point> graph) {
    // Brute force: O(N^3)
    // Use hash table: O(N^2), find the most common slope and y-intercept.
    map<line, int> record;
    for (int i = 0; i < graph.size(); i++) {
        for (int j = i+1; j < graph.size(); j++) {
            line l = connectPoints(graph[i], graph[j]);
            if (record.find(l) != record.end()) {
                record[l] += 1;
            } else {
                record.insert(make_pair(l, 1));
            }
        }
    }

    map<line, int>::iterator it = record.begin();
    int MAX = (*it).second;
    line maxLine = (*it).first;

    for (it; it != record.end(); it++) {
        if (MAX < (*it).second) {
            MAX = (*it).second;
            maxLine = (*it).first;
        }
    }
    return maxLine;
}

int main() {
    vector<point> graph;
    graph.push_back(point(3.0, 5.0));
    graph.push_back(point(4.0, 4.0));
    graph.push_back(point(5.0, 5.0));
    graph.push_back(point(7.0, 7.0));
    graph.push_back(point(6.0, 10.0));
    line ret = findLine(graph);
    cout << "the line: " << "y = " << ret.slope << " * x + " << ret.yIntercept
         << endl;
    return 0;
}
