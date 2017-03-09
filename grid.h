#ifndef GRID_H
#define GRID_H

#include "critter.h"
#include "menu.h"

Critter*** makeBoard(); //Create a 2D array of size 20*20 of pointers to Critters
void populateBoard(Critter***); //Fill the board with 100 Ants and 5 Doodlebugs in a random locations
void displayBoard(Critter***); //Print the board
void destroyBoard(Critter***); //Deallocate all memory from the heap
void moveBoard(Critter***); //Call the virtual move() function on each object on the board
void breedBoard(Critter***); //Call the virtual breed() functino on each object on the board
void deleteObject(Critter***, int, int);

#endif
