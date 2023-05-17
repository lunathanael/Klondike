#include "table.h"

#include <random>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

std::map<char, int> char_suits = {
	{'C', CLUBS}, {'S', SPADES}, {'D', DIAMONDS}, {'H', HEARTS}
};

const char ascii_suits[] = "CSDH.";


std::map<char, int> char_ranks = {
	{'A', ACE}, {'2', TWO}, {'3', THREE}, {'4', FOUR}, 
	{'5', FIVE}, {'6', SIX}, {'7', SEVEN}, {'8', EIGHT}, 
	{'9', NINE}, {'T', TEN}, {'J', JACK}, {'Q', QUEEN}, 
	{'K', KING}
};

const char ascii_ranks[] = "A23456789TJQK";

static inline void Print_card(CARDS card) {
	cout << ascii_suits[(card / 13)];
	cout << ascii_ranks[(card % 13)];
}


void Print_deck(DECK* deck) {
	for (int i = 0; i < ALL_DECKS_SIZE; ++i) {
		Print_card(deck->cards[i]);
		cout << ' ';
	}
	cout << endl;
}





void initGame() {

}









