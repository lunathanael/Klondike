#include "types.h"
#include "table.h"
#include "moves.h"

// IO
#include <iostream>
#include "io.h"

using namespace std;


enum COMMANDS
{
	unrecognized_command, new_game, display_screen, help, quit, move_command
};

#include <map>
static map<string, COMMANDS> MAP_COMMANDS =
{
	{"newgame", new_game}, {"d", display_screen}, {"help", help}, {"quit", quit}, {"move", move_command}
};


static void Parse_help(vector<string> tokens) {
	if (tokens.size() == 1) {
		cout << "\nCommands:\n\"help\":      Provides help information for commands.\n\"newgame\":   Starts a new Klondike game.\n\"d\":         Prints current game state.\n\"quit\":      Closes game client.\n\"move\":      Move card location.\n\n";
		return;
	}
	switch (MAP_COMMANDS[tokens[1]])
		{
		case (quit):
		{
			cout << "Closes game client.\n\nquit\n\n";
			break;
		}
		case (help):
		{
			cout << "Provides help information for commands.\n\nhelp command\n\n	command - displays help information on that command.";
			break;
		}
		case (display_screen):
		{
			cout << "Prints current game state.\n\nd\n\n";
			break;
		}
		case (new_game):
		{
			cout << "Starts a new Klondike game.\n\nnewgame\n\n";
			break;
		}
		case (move_command):
		{
			cout << "Move card location.\n\nmove [operation] [source] [destination]\n\n";
			cout << "	operation - type of move to be performed\n";
			cout << "		 T	move the stock card to the waste pile or turning over the stock.\n";
			cout << "		pp	move a partial pile or card from one pile to another.\n";
			cout << "		sp	move a card from the stock to a pile, only destination is needed to be specified.\n";
			cout << "		sf	move a card from the stock to a foundation, only destination is needed to be specified.\n";
			cout << "		pf	move a card from a pile to a foundation.\n";
			cout << "		fp	move a card from a foundation to a pile.\n\n";
			cout << "	source - location to move card from\n";
			cout << "		[P]	location of partial pile to move. (Ex: 23, move the partial pile at the 2nd pile starting from the 3rd card from the top)\n";
			cout << "		[F]	the suit of the foundation to move the card from. (Ex: C)\n";
			cout << "	destination - location to move card to\n";
			cout << "		[P]	the pile to move the card to. (Ex: 2, the 2nd pile)\n";
			cout << "		[F]	the suit of the foundation to move the card to. (Ex: C)\n\n";
			cout << "Note: Illegal moves will be ignored.\n\n";
			break;
		}
		case (unrecognized_command):
		{
			cout << "Unknown command\n";
			break;
		}
	}
	return;
}


void Parse_move(vector<string> tokens, TABLE*gamestate) {
	if (tokens.size() == 1) {
		cout << "Invalid command size!\n";
	}
	else if (tokens.at(1) == "T") {
		Turn_stock(&gamestate->stock);
	}
	else if (tokens.at(1) == "pp") {
	}
	else if (tokens.at(1) == "sp") {
	}
	else if (tokens.at(1) == "sf") {
		if (tokens.at(2).length() != 1) {
			cout << "Formatting error!\n";
			return;
		}
		Stock_to_foundation(&gamestate->stock, &gamestate->foundations[char_suits[tokens.at(2)[0]]], char_suits[tokens.at(2)[0]]);
	}
	else if (tokens.at(1) == "pf") {
		if (tokens.at(2).length() != 1) {
			cout << "Formatting error!\n";
			return;
		}
		if (tokens.at(3).length() != 1) {
			cout << "Formatting error!\n";
			return;
		}
		int pile = stoi(tokens.at(2));
		Pile_to_foundation(&gamestate->piles[pile], &gamestate->foundations[char_suits[tokens.at(3)[0]]], char_suits[tokens.at(3)[0]]);
	}
	else if (tokens.at(1) == "fp") {
		if (tokens.at(2).length() != 1) {
			cout << "Formatting error!\n";
			return;
		}
		if (tokens.at(3).length() != 1) {
			cout << "Formatting error!\n";
			return;
		}
		int pile = stoi(tokens.at(3));
		Foundation_to_pile(&gamestate->piles[pile], &gamestate->foundations[char_suits[tokens.at(2)[0]]], char_suits[tokens.at(2)[0]]);
	}
	else {
		cout << "Invalid Command!\n";
	}

	return;
}


int main() {
	cout << "Welcome to Solitaire: Klondike, a command-line game by Nathanael Lu.\n";
	cout << "Type \"help\" for command options.\n";

	TABLE gamestate;
	bool gamestarted = false;
	while (true) {
		string input;


		// get user / GUI input
		if (!getline(std::cin, input))
		{
			// continue the loop
			break;
		}

		// make sure input is available
		if (!input.length())
		{
			// continue the loop
			continue;
		}

		//Split the string into tokens to make it easier to work with
		vector<string> tokens = split_command(input);

		switch (MAP_COMMANDS[tokens[0]])
		{
			case (quit):
			{
				return 0;
			}
			case (help):
			{
				Parse_help(tokens);
				break;
			}
			case (display_screen):
			{
				if (gamestarted) {
					Print_gamestate(&gamestate);
				}
				else {
					cout << "No game available!\n";
				}
				break;
			}
			case (new_game): 
			{
				gamestate = Start_game();
				gamestarted = true;
				break;
			}
			case (move_command):
			{
				if (gamestarted) {
					Parse_move(tokens, &gamestate);
				}
				else {
					cout << "No game available!\n";
				}
				break;
			}
			case (unrecognized_command):
			{
				cout << "Unknown command\n";
				break;
			}
		}
		continue;
		int stock;
		int foundation;
		cin >> stock >> foundation;

		if (stock == 1) {
			Stock_to_foundation(&gamestate.stock, &gamestate.foundations[foundation - 1], foundation);
		}
		else {
			Turn_stock(&gamestate.stock);
		}
	}

	return 0;
}