#ifndef MOVES_H
#define MOVES_H

#include "types.h"

static inline void Update_pile(PILE* pile) {
	if (pile->revealed == pile->cardNumber) {
		--pile->revealed;
	}
	if (pile->revealed < 0) {
		pile->revealed = 0;
	}
	return;
}



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
		CARDS stock_card = stock->stack[stock->faceCard];

		// Check for same suit and 1 higher
		if (get_card_suit(stock_card) != foundationIndex) {
			// ILLEGAL MOVE, not same suit
			return;
		}
		if (foundation->cards == 0) {
			if (get_card_rank(stock_card) != ACE) {
				return;
			}
		}
		else if ((stock_card - 1) != (foundation->stack[foundation->cards - 1])) {
			// ILLEGAL MOVE, not 1 higher
			return;
		}


		// add foundation card;
		foundation->stack[foundation->cards++] = stock_card;
		
		// remove stock card
		stock->stack[stock->faceCard] = NO_CARD;
		Turn_stock(stock);
		--stock->cardsLeft;
	}
	return;
}

static inline void Pile_to_foundation(PILE* pile,  FOUNDATION* foundation, int foundationIndex) {
	if (pile->cardNumber != 0) { // cards exist
		CARDS pile_card = pile->pile[pile->cardNumber - 1]; // Top card

		// Check for same suit and 1 higher
		if (get_card_suit(pile_card) != foundationIndex) {
			// ILLEGAL MOVE, not same suit
			return;
		}
		if (foundation->cards == 0) {
			if (get_card_rank(pile_card) != ACE) {
				return;
			}
		}
		else if ((pile_card - 1) != (foundation->stack[foundation->cards - 1])) {
			// ILLEGAL MOVE, not 1 higher
			return;
		}

		// add foundation card;
		foundation->stack[foundation->cards++] = pile_card;

		// remove pile card
		pile->pile[--pile->cardNumber] = NO_CARD;
		Update_pile(pile);
	}
	return;
}

static inline void Foundation_to_pile(PILE* pile,  FOUNDATION* foundation, int foundationIndex) {
	if (foundation->cards != 0) { // cards exist
		CARDS foundation_card = foundation->stack[foundation->cards - 1]; // Top card

		if (pile->cardNumber != 0) {
			// Check for opposite color suit and one lower
			if (get_card_rank(foundation_card) == KING) {
				return;
			}
			else if ((foundationIndex >> 1) ^ (get_card_suit(pile->pile[pile->cardNumber - 1]) >> 1)) {
				// ILLEGAL MOVE, not same suit
				return;
			}
			else if ((foundation_card + 1) != (foundation->stack[foundation->cards - 1])) {
				// ILLEGAL MOVE, not 1 higher
				return;
			}
		}

		// add pile card
		pile->pile[pile->cardNumber++] = foundation_card;
		Update_pile(pile);

		// remove foundation card;
		foundation->stack[--foundation->cards] = NO_CARD;
	}
	return;
}

static inline void Pile_to_pile(PILE* pile, int card_index, FOUNDATION* foundation, int foundationIndex) {
	if (pile->cardNumber != 0) { // cards exist
		int card_index_from_bottom = pile->cardNumber - card_index;
		if (card_index >= pile->revealed) { // Card is revealed
			
		}
	}
	return;
}



static inline void Move_pile() {


};




#endif