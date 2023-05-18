#ifndef TABLE_H
#define TABLE_H

#include "types.h"



/* FUNCTIONS */
TABLE Start_game();

void Print_stock_card(STOCK* stock);
void Print_stack(CARDS cards[], int number_of_cards);
void Print_gamestate(TABLE* gamestate);



#endif