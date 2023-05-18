#include "types.h"
#include "table.h"
#include "moves.h"

#include <iostream>


using namespace std;



int main() {
	TABLE gamestate = Start_game();
	while (1) {
		getchar();
		Print_gamestate(&gamestate);
	}

	return 0;
}