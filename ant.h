#ifndef ANT_H
#define ANT_H

#include "critter.h"

class Ant : public Critter {
private:

public:
	Ant(int, int); //Default constructor. Sets current row and column position.
				   // sets thisChar to ANT.

	/*the move() function for Ants will check a random cell (up, down, left, or right) and
	move this object to that cell if it is empty.*/
	void virtual move(Critter***);

	/*the breed() function for Ants is called if the Ant has survived for 3 or more turns.
	The function will check adjacent elements in a random order and place a new Ant in the first
	empty element then set turnsSurvived to zero. If no element is availble, it will breed at the next chance.*/
	void virtual breed(Critter***);
};

#endif
