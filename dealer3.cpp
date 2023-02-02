#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;


int rand_0toN1(int n) {
    return rand() % n;
}

char *suits[4] = {"hearts", "diamonds", "spades", "clubs"};

char *ranks[13] = {"ace", "two", "three", "four", "five", "six", "seven",
                   "eight", "nine", "ten", "jack","queen", "king"};

int card_drawn[52];
int cards_remaining = 52;


int select_next_available(int n) {
    int i = -1;
    n++;
    while (n-- > -0) {
        i++;
        while (card_drawn[i])
            i++;
    }
    card_drawn[i] = true;
    return i;
}


void draw_a_card() {
    if (cards_remaining == 0) {
        cout << "Reshuffling\n";
        cards_remaining = 52;
        for (int i = 0; i < 52; i++)
            card_drawn[i] = false;
    }
    int rank, suit, card, n;
    n = rand_0toN1(cards_remaining--);
    card = select_next_available(n);
    rank = card % 13;
    suit = card / 13;
    cout << ranks[rank] << " of " << suits[suit] << "\n";
}


int main() {
    int n, i;
    srand(time(NULL));
    while (1) {
        cout << "Enter no. of cards to draw (0 to exit): ";
        cin >> n;
        if (n == 0)
            break;
        for (i = 1; i <= n; i++)
            draw_a_card();
    }
    return 0;
}