#ifndef TYPES_H
#define TYPES_H


#define NUMBER_OF_DECKS 1
#define NUMBER_OF_PILES 7

#define NUMBER_OF_SUITS 4
#define CARDS_IN_SUIT 13

static constexpr int DECK_SIZE = (NUMBER_OF_SUITS * CARDS_IN_SUIT);
static constexpr int ALL_DECKS_SIZE = (NUMBER_OF_DECKS * DECK_SIZE);
static constexpr int STOCK_SIZE = (ALL_DECKS_SIZE - (NUMBER_OF_PILES * (NUMBER_OF_PILES + 1) / 2)); // last element is the no face card

static constexpr int MAX_PILE_SIZE = (CARDS_IN_SUIT + NUMBER_OF_PILES);

enum RANKS : int{
	ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, NO_RANK
};

enum SUITS : int {
	CLUBS, SPADES, DIAMONDS, HEARTS
}; // 00 01 10 11

enum CARDS : int {
	CA, C2, C3, C4, C5, C6, C7, C8, C9, CT, CJ, CQ, CK,
	SA, S2, S3, S4, S5, S6, S7, S8, S9, ST, SJ, SQ, SK,
	DA, D2, D3, D4, D5, D6, D7, D8, D9, DT, DJ, DQ, DK,
	HA, H2, H3, H4, H5, H6, H7, H8, H9, HT, HJ, HQ, HK, NO_CARD
};

// left to right
enum PILES : int {
	PILE1, PILE2, PILE3, PILE4, PILE5, PILE6, PILE7
};



struct CARD {
	RANKS rank;
	SUITS suit;
	bool revealed = false;
};

#include <algorithm>

struct DECK {
	CARDS cards[DECK_SIZE];
	int currentCard = 0;

	DECK() {
		std::fill_n(cards, DECK_SIZE, NO_CARD);
	}
};


struct FOUNDATION {
	CARDS stack[CARDS_IN_SUIT];
	int cards = 0;
	FOUNDATION() {
		std::fill_n(stack, CARDS_IN_SUIT, NO_CARD);
	}
};


struct STOCK {
	CARDS stack[STOCK_SIZE];
	int cardsLeft = STOCK_SIZE;
	int faceCard = -1; // No card at -1 and STOCK_SIZE
	STOCK() {
		std::fill_n(stack, STOCK_SIZE, NO_CARD);
	}
};

struct PILE {
	CARDS pile[MAX_PILE_SIZE];
	int revealed = 0;
	int cardNumber = 0;
	PILE() {
		std::fill_n(pile, MAX_PILE_SIZE, NO_CARD);
	}
};


struct TABLE {
	FOUNDATION foundations[NUMBER_OF_SUITS];
	STOCK stock;
	PILE piles[NUMBER_OF_PILES];
	TABLE() {
		for (int i = 0; i < NUMBER_OF_PILES; ++i) {
			piles[i].revealed = i; // by index
			piles[i].cardNumber = i + 1;
		}
	}
};

static constexpr int get_card_suit(CARDS card) {
	return (card / 13);
}

static constexpr int get_card_rank(CARDS card) {
	return (card % 13);
}


#define ENABLE_INCR_OPERATORS_ON(T)                                \
inline T& operator++(T& d) { return d = T(int(d) + 1); }           \
inline T& operator--(T& d) { return d = T(int(d) - 1); }


ENABLE_INCR_OPERATORS_ON(CARDS)
ENABLE_INCR_OPERATORS_ON(PILES)
ENABLE_INCR_OPERATORS_ON(SUITS)






#endif