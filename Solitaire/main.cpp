#include "types.h"
#include "deck.h"
#include "table.h"

#include <iostream>


using namespace std;



int main() {
	DECK deck;
	Fill_deck(&deck);
	Shuffle_deck(&deck);
	Print_deck(&deck);


	return 0;
}