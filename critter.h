#ifndef CRITTER_H
#define CRITTER_H

enum character {ANT, DOODLEBUG};
enum direction {UP, DOWN, LEFT, RIGHT};

class Critter {

private:
	character thisChar; //Enum variable to keep track of object type
	int rowPos; //Tracks the object's current row position
	int colPos; //Track the object's current column position
	int turnsSurvived; //Tracks number of moves the object has existed. Initialized to zero
	bool movedThisTurn; //Tracks if the object has passed through the move() function

public:
	Critter(); //Default constructor. Initializes turnsSurvived to zero and
			   // movedThisTurn to true (object will not moved during the turn it's created)

	//get and set functions
	void setRowPos(int);
	int getRowPos();
	void setColPos(int);
	int getColPos();
	void setTurnsSurvived(int);
	int getTurnsSurvived();
	void setMovedThisTurn(bool);
	bool getMovedThisTurn();
	void setThisChar(character);
	character getThisChar();

	//Virtual functions to distinguish between Ant and Doodlebug.
	//Does nothing for a Critter object.
	void virtual move(Critter***);
	void virtual breed(Critter***);
};



#endif
