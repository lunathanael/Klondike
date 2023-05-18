#ifndef MOVES_H
#define MOVES_H

#include "types.h"


static inline void Turn_stock(STOCK* stock) {
	if (stock->cardsLeft == 0) {
		// ILLEGAL MOVE
		return;
	}
	while (true) {
		++stock->faceCard;
		if (stock->faceCard > STOCK_SIZE) {
			stock->faceCard = -1;
			return;
		}
		if (stock->faceCard == STOCK_SIZE) {
			return;
		}
		if (stock->stack[stock->faceCard] != NO_CARD) {
			return;
		}
	}
};

static inline void Stock_to_foundation(STOCK* stock, FOUNDATION* foundation, int foundationIndex) {
	if (stock->faceCard != -1 && stock->faceCard != STOCK_SIZE) { // faceCard exists
		CARDS stockCard = stock->stack[stock->faceCard];

		// Check for same suit and 1 higher
		if (get_card_suit(stockCard) != foundationIndex) {
			// ILLEGAL MOVE, not same suit
			return;
		}
		if (foundation->cards != 0 && (stockCard - 1) != (foundation->stack[foundation->cards - 1])) {
			// ILLEGAL MOVE, not 1 higher
			return;
		}


		// add foundation card;
		foundation->stack[foundation->cards++] = stockCard;
		
		// remove stock card
		stock->stack[stock->faceCard] = NO_CARD;
		Turn_stock(stock);
		--stock->cardsLeft;
	}
}

static inline void Foundation_to_stock(STOCK* stock, FOUNDATION* foundation) {
	if (foundation->cards > 0) { // faceCard exists
		// add foundation card;
		foundation->stack[foundation->cards++];

		// remove stock card
		stock->stack[stock->faceCard] = NO_CARD;
		Turn_stock(stock);
		--stock->cardsLeft;
	}
}


static inline void Move_pile() {


};




#endif