/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Lab 5 - Predator vs Prey
***************************/

#ifndef DOODLE_H
#define DOODLE_H

#include "critter.h"

class Doodle : public Critter {
private:
	int starveCount; //Tracks how many turns the Doodlebug has gone without eating an Ant
public:
	Doodle(int, int); //Default constructor. Sets current row and column position.
					  // Initializes starveCount to zero and set thisChar to DOODLEBUG.

	//get and set methods
	void setStarveCount(int);
	int getStarveCount();

	/* move() function for Doodlebugs attempts to find an adjacent ant in a random direction
	and consumes the ant if one exists. If one does not exists, attempts to move in a random
	direction. If there is a Doodlebug there, this object will not move. */
	void virtual move(Critter***);

	/* breed() function for Doodlebug is called if the Doodlebug has survived for 8 or more turns.
	The function will check adjacent elements in a random order and place a new Doodlebug in the first
	empty element then set turnsSurvived to zero. If no element is availble, it will breed at the next chance.*/
	void virtual breed(Critter***);
};

#endif
