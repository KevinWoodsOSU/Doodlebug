#include "critter.h"
#include "menu.h"

Critter::Critter() {
	setTurnsSurvived(0);
	setMovedThisTurn(true);
}

void Critter::setRowPos(int r) {
	rowPos = r;
}

int Critter::getRowPos() {
	return rowPos;
}

void Critter::setColPos(int c) {
	colPos = c;
}

int Critter::getColPos() {
	return colPos;
}

void Critter::setTurnsSurvived(int t) {
	turnsSurvived = t;
}

int Critter::getTurnsSurvived() {
	return turnsSurvived;
}

void Critter::setMovedThisTurn(bool t) {
	movedThisTurn = t;
}

bool Critter::getMovedThisTurn() {
	return movedThisTurn;
}

void Critter::setThisChar(character c) {
	thisChar = c;
}

character Critter::getThisChar() {
	return thisChar;
}

void Critter::move(Critter*** c){
	cout << "move error. Critter->move()";
}

void Critter::breed(Critter*** b) {
	cout << "breed error. Critter->breed()";
}


