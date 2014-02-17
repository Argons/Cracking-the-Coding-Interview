# include <iostream>
# include <vector>
using namespace std;

// Implement the “paint fill” function that one might see on many image editing
// programs. That is, given a screen (represented by a 2-dimensional array of 
// Colors), a point, and a new color, fill in the surrounding area until you hit
// a border of that color.

enum color { white, black, red, green, yellow, blue, brown, purple };

void paintFill(vector<vector<int> > &screen, int x, int y, 
               color initial, color paint) {
    if (x < 0 || x >= screen.size() || y < 0 || y >= screen[0].size())
        return;
    if (screen[x][y] != initial)
        return;
    screen[x][y] = paint;
    paintFill(screen, x+1, y, initial, paint);
    paintFill(screen, x-1, y, initial, paint);
    paintFill(screen, x, y+1, initial, paint);
    paintFill(screen, x, y-1, initial, paint);
}

void paintFill(vector<vector<int> > &screen, int x, int y, color paint) {
    if (screen[x][y] == paint)
        return;
    paintFill(screen, x, y, color(screen[x][y]), paint);
}


void display(vector<vector<int> > &screen) {
    for (int i = 0; i < screen.size(); i++) {
        for (int j = 0; j < screen[0].size(); j++) {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int> > screen(20, vector<int>(20, 0));
    display(screen);
    paintFill(screen, 10, 10, blue);
    display(screen);
    return 0;
}
