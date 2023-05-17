#include "deck.h"

#include <random>
#include <algorithm>

using namespace std;

void Fill_deck(DECK* deck) {
    int index = 0;
    for (int current_deck = 0; current_deck < NUMBER_OF_DECKS; ++current_deck) {
        // for each 52 cards
        for (CARDS card = CA; card < DECK_SIZE; ++card) {
            deck->cards[index] = card;
            ++index;
        }
    }
}



void Shuffle_deck(CARDS deck[])
{
    // time-based seed
    unsigned seed = 0;
    shuffle(deck, deck + DECK_SIZE, default_random_engine(seed));
}

