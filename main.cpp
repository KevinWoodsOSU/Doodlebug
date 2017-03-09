#include "menu.h"
#include "critter.h"
#include "ant.h"
/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Lab 5 - Predator vs Prey
***************************/

#include "grid.h"
#include "doodle.h"

int main() {
	srand(time(0));
	Critter*** board = makeBoard();

	clearScreenUnix();
	bool cont = true;
	while (cont) {
		int turns = getInt("How many time steps will this program iterate through?: ");
		cin.ignore();
		populateBoard(board);
		for(int i = 0; i < turns; i++) {
			clearScreenUnix();
			cout << "Turn " << i + 1 << " of " << turns << endl;
			cout << "O = Ant \t X = Doodlebug" << endl;
			displayBoard(board);
			enterToContinue();
			moveBoard(board);
			breedBoard(board);
		}
		cont = yesOrNo("Would you like to run this program again? (y/n): ");
		clearScreenUnix();
		destroyBoard(board);
		board = makeBoard();
	}

	destroyBoard(board);
	
	return 0;
}
