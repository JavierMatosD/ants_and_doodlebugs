/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Organism.h"
#include "Grid.h"
#include <iostream>

/**
 * constructor for Organism
 * @param void NONE
 * @return void NONE
 */
Organism::Organism(){
	     myGrid = NULL;
		 x =0;
		 y =0;
		 count=0;
		 gridSize=0;
		 moved=false;
}
/**
 * constructor for Organism
 * @param Grid *myGrid pointer to grid
 * @param int x coordinate
 * @param int y coordinate
 * @param int gridSize number of Ogranism
 */
Organism::Organism(Grid *gridPtr, int xCoord, int yCoord, int sizeOfGrid) {
	myGrid = gridPtr;
	x = xCoord;
	y = yCoord;
	gridSize = sizeOfGrid;
	count = 0;
	moved =false;
	gridPtr->setOrganism(this, x, y);

}
/**
 * checks the surrounding areas to see if the organism can move
 * @param void NONE
 * @return True or False (true if there is free space otherwise false
 */
bool Organism::canMove(){
	bool up   = false;
	bool down = false;
	bool left = false;
	bool right= false;

	//check the right
	if((x < gridSize - 1) && (myGrid->getOrganism(x + 1,y) == NULL)){
	 right = true;
	}
	//check the left
	if((x > 0 ) && (myGrid->getOrganism(x - 1, y) == NULL)){
		left = true;
	}
	//check up
	if((y < gridSize - 1) && (myGrid->getOrganism(x,y+1) == NULL)){
		up = true;
	}
	//check down
	if((y > 0) && (myGrid->getOrganism(x,y-1) == NULL)){
		down=true;
	}
	return(left || up || down || right);
}
Organism::~Organism() {}

