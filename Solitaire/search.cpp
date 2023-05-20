#include "search.h"
#include "moves.h"

#include <iostream>
using namespace std;


static inline bool Search_pp(TABLE *gamestate) {
    int pile_chains[NUMBER_OF_PILES];


    for (int i = 0; i < NUMBER_OF_PILES; ++i) {
        int current_chain = 0;
        if (gamestate->piles[i].cardNumber != 0) {
            ++current_chain;
            int select_card_index = gamestate->piles[i].revealed;
            for (; select_card_index < (gamestate->piles[i].cardNumber - 1); ) {
                CARDS first_card = gamestate->piles[i].pile[select_card_index];
                ++select_card_index;
                CARDS second_card = gamestate->piles[i].pile[select_card_index];
                if ((get_card_suit(first_card) >> 1) == (get_card_suit(second_card) >> 1)) {
                    break;
                }
                else {
                    if ((get_card_rank(first_card) - 1) != get_card_rank(second_card)) {
                        break;
                    }
                }
                ++current_chain;
            }
            if (gamestate->piles[i].revealed == 0) {
                if (get_card_rank(gamestate->piles[i].pile[0]) == KING) {
                    current_chain = 0;
                }
            }
        }
        pile_chains[i] = current_chain;
    }


    for (int pile_index = 0; pile_index < NUMBER_OF_PILES; ++pile_index) {
        if (pile_chains[pile_index] == 0) {
            continue;
        }
        for (int pile_target = 0; pile_target < NUMBER_OF_PILES; ++pile_target) {
            if (pile_target == pile_index) {
                continue;
            }
            if (Pile_to_pile(&gamestate->piles[pile_index], &gamestate->piles[pile_target], pile_chains[pile_index])) {
                cout << "Moved " << pile_chains[pile_index] << " card(s) from pile " << (pile_index + 1) << " to pile " << (pile_target + 1) << ".\n";
                return true;
            }
        }
    }

    return false;
}


bool Move_hint(TABLE* gamestate) {
    try {
        // sf
        if (Stock_to_foundation(gamestate)) {
            cout << "Moved card from stock to foundation.\n";
            return true;
        }
        // pf
        for (PILES pile = PILE7; pile >= 0; --pile) {
            if (Pile_to_foundation(gamestate, pile)) {
                cout << "Moved card from pile " << (pile + 1) << " to foundation.\n";
                return true;
            }
        }

        // sp
        for (PILES pile = PILE7; pile >= 0; --pile) {
            if (Stock_to_pile(&gamestate->piles[pile], &gamestate->stock)) {
                cout << "Moved card from stock to pile " << (pile + 1) << ".\n";
                return true;
            }
        }

        // pp
        if (Search_pp(gamestate)) {
            return true;
        }

        // T
        if (Turn_stock(&gamestate->stock)) {
            cout << "Turned stock.\n";
            return true;
        }

        return false;
    }
    catch (...) {
        throw(505);
        return false;
    }

    return false;

}







