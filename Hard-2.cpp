#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// Write a method to shuffle a deck of cards. It must be a perfect shuffle - 
// in other words, each 52! permutations of the deck has to be equally likely.
// Assume that you are given a random number generator which is perfect.

void shuffleCards(vector<int> &cards) {
    for (int i = 0; i < cards.size(); i++) {
        int seed = cards.size() - i;
        int index = rand() % seed + i;
        swap(cards[i], cards[index]);
    }
}

int main() {
    vector<int> cards(52 ,0);
    for (int i = 0; i < 52; i++) {
        cards[i] = i + 1;
    }
    shuffleCards(cards);
    for (int i = 0; i < 52; i++) {
        cout << cards[i] << " ";
    }
    cout << endl;
    return 0;
}
