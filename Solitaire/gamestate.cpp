#include "gamestate.h"
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




static inline bool Game_over(GAMESTATE* gamestate) {

    for (int foundation = 0; foundation < NUMBER_OF_SUITS; ++foundation) {
        if (gamestate->foundations[foundation].cards != CARDS_IN_SUIT) {
            goto No_moves;
        }
    }
    gamestate->game_result = 1;
    return true;
No_moves:

    return false;
}


//static inline 
void Print_stock_card(STOCK* stock) {
    if (stock->faceCard == -1 || stock->faceCard == (STOCK_SIZE)) {
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

void Print_pile(PILE* pile, bool hidden) {
    for (int i = 0; i < pile->cardNumber; ++i) {
        if (i >= pile->revealed || !hidden) {
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


void Print_gamestate(GAMESTATE * gamestate, bool hidden) {
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
    cout << "                 MOVES: " << gamestate->moves << endl;

    for (PILES pile = PILE7; pile >= 0; --pile) {
        // Each card
        cout << endl << pile + 1 << ':';
        Print_pile(&gamestate->piles[pile], hidden);
    }
    cout << endl;
    if (Game_over(gamestate)) {
        cout << "Game result: ";
        switch (gamestate->game_result)
        {
            case (1):
            {
                cout << "Victory";
                break;
            }
            case (-1):
            {
                cout << "Loss";
                break;
            }
        }
        cout << endl;
    }
}



GAMESTATE Start_game() {
    GAMESTATE gamestate;


    DECK deck;
    Fill_deck(&deck);
    Shuffle_deck(&deck);

    // 7 piles
    for (PILES pile = PILE1; pile < NUMBER_OF_PILES;) {
        // Each card
        CARDS* start = (deck.cards + deck.currentCard);
        ++pile;
        deck.currentCard += (pile);
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









