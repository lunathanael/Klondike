#ifndef TABLE_H
#define TABLE_H

#include "types.h"
#include <map>


extern std::map<char, int> char_suits;


/* FUNCTIONS */
TABLE Start_game();

void Print_stock_card(STOCK* stock);
void Print_stack(CARDS cards[], int number_of_cards);
void Print_gamestate(TABLE* gamestate, bool hidden=true);



#endif