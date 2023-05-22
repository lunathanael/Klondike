#include "deck.h"

#include <random>
#include <ctime>
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



void Shuffle_deck(DECK*deck)
{
    // time-based seed
    //shuffle(deck->cards, deck->cards + DECK_SIZE, default_random_engine(seed));
    random_shuffle(deck->cards, deck->cards + DECK_SIZE);
}


