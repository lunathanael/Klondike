#include "table.h"
#include "deck.h"

#include <random>
#include <algorithm>
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


//static inline 
void Print_stock_card(STOCK* stock) {
    if (stock->faceCard == -1 || stock->faceCard == (STOCK_SIZE + 1)) {
        cout << "mt";
        return;
    }
    
    if (stock->stack[stock->faceCard] != NO_CARD) {
        cout << ascii_suits[get_card_suit(stock->stack[stock->faceCard])];
        cout << ascii_ranks[get_card_rank(stock->stack[stock->faceCard])];
    }
    return;
}

//static inline 
void Print_foundation_card(FOUNDATION * foundation) {
    if (foundation->cards == 0) {
        cout << "mt ";
        return;
    }

    cout << ascii_suits[get_card_suit(foundation->stack[foundation->cards - 1])];
    cout << ascii_ranks[get_card_rank(foundation->stack[foundation->cards - 1])] << ' ';
    return;
}

static inline void Print_card(CARDS card) {
    if (card != NO_CARD) {
        cout << ascii_suits[get_card_suit(card)];
        cout << ascii_ranks[get_card_rank(card)];
    }
    return;
}

void Print_pile(PILE* pile) {
    for (int i = 0; i < pile->cardNumber; ++i) {
        if (i >= pile->revealed) {
            Print_card(pile->pile[i]);
        }
        else {
            cout << "**";
        }
        cout << ' ';
    }
    cout << endl;
}

void Print_stack(CARDS cards[], int number_of_cards) {
    
	for (int i = 0; i < number_of_cards; ++i) {
		Print_card(cards[i]);
		cout << ' ';
	}
	cout << endl;
}


void Print_gamestate(TABLE* gamestate) {
    cout << endl;
    cout << "Current stock card: ";
    Print_stock_card(&gamestate->stock);


    cout << "       Foundations: ";
    Print_foundation_card(&gamestate->foundations[0]);
    Print_foundation_card(&gamestate->foundations[1]);
    Print_foundation_card(&gamestate->foundations[2]);
    Print_foundation_card(&gamestate->foundations[3]);

    cout << "\n                                          C  S  D  H ";
    cout << "\nPILES:";

    for (PILES pile = PILE7; pile >= 0; --pile) {
        // Each card
        cout << endl << pile + 1 << ':';
        Print_pile(&gamestate->piles[pile]);
    }
    cout << endl;
}



TABLE Start_game() {
    TABLE gamestate;


    DECK deck;
    Fill_deck(&deck);
    Shuffle_deck(&deck);

    // 7 piles
    for (PILES pile = PILE1; pile < NUMBER_OF_PILES;) {
        // Each card
        CARDS* start = (deck.cards + deck.currentCard);
        deck.currentCard += (++pile);
        CARDS* end = (deck.cards + deck.currentCard);
        copy(start, end, gamestate.piles[pile - 1].pile);
    }

    // rest into stock
    CARDS* start = (deck.cards + deck.currentCard);
    deck.currentCard += STOCK_SIZE;
    CARDS* end = (deck.cards + deck.currentCard);
    copy(start, end, gamestate.stock.stack);


    return gamestate;
}









