#include "grid.h"
#include "ant.h"
#include "doodle.h"
#include "menu.h"

Critter*** makeBoard() {
	Critter*** board;
	board = new Critter**[20];

	for (int i = 0; i < 20; i++)
		board[i] = new Critter*[20];


	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			board[i][j] = NULL;

	return board;
}

void populateBoard(Critter*** board) {
	int antCount = 0;
	while (antCount < 100) {
		int row = rand() % 20;
		int col = rand() % 20;
		if (board[row][col] == NULL) {
			board[row][col] = new Ant(row, col);
			antCount++;
		}
	}
	int doodleCount = 0;
	while (doodleCount < 5) {
		int row = rand() % 20;
		int col = rand() % 20;
		if (board[row][col] == NULL) {
			board[row][col] = new Doodle(row, col);
			doodleCount++;
		}
	}
}

void displayBoard(Critter*** board) {
	for (int i = 0; i < 20; i++) {
		cout << " ";
		for (int j = 0; j < 20; j++) {
			if (j == 0) {
				if (board[i][j] == NULL)
					cout << ".";
				else if (board[i][j]->getThisChar() == ANT)
					cout << "O";
				else if (board[i][j]->getThisChar() == DOODLEBUG)
					cout << "X";
			}
			else {
				cout << " ";
				if (board[i][j] == NULL)
					cout << ".";
				else if (board[i][j]->getThisChar() == ANT)
					cout << "O";
				else if (board[i][j]->getThisChar() == DOODLEBUG)
					cout << "X";
			}
		}
		cout << endl;
	}
}

void destroyBoard(Critter*** board) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			delete board[i][j];
		}
		delete[] board[i]; 
	}
	delete[] board;
	board = NULL;
}

void moveBoard(Critter*** board) {
	//Set all current bug's movedThisTurn to false to indicate they are
	//the original bugs to be moved.
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (board[i][j] != NULL) {
				board[i][j]->setMovedThisTurn(false);
			}
		}
	}

	//Find all doodlebugs and move them if they are not new
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (board[i][j] != NULL) {
				if (board[i][j]->getThisChar() == DOODLEBUG) {
					if (board[i][j]->getMovedThisTurn() == false) {
						board[i][j]->move(board);
					}
				}
			}
		}
	}

	//Find all ants and move them if they are not new
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (board[i][j] != NULL) {
				if (board[i][j]->getThisChar() == ANT) {
					if (board[i][j]->getMovedThisTurn() == false) {
						board[i][j]->move(board);
					}
				}
			}
		}
	}
}

void breedBoard(Critter*** board) {
	//Find all ants and call the breed function
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (board[i][j] != NULL) {
				if (board[i][j]->getThisChar() == ANT) {
					board[i][j]->breed(board);
				}
			}
		}
	}

	//Find all doodlebugs and call the breed function
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (board[i][j] != NULL) {
				if (board[i][j]->getThisChar() == DOODLEBUG) {
					board[i][j]->breed(board);
				}
			}
		}
	}
}

void deleteObject(Critter*** board, int row, int column) {
	delete board[row][column];
	board[row][column] = NULL;
}
