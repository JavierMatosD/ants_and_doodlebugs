/*
 * Doodlebug.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"
#include "Grid.h"
#include <iostream>

class Doodlebug: public Organism {

public:
	Doodlebug();
	Doodlebug(Grid *myGrid, int x, int y, int gridSize);
	bool starving();
	void birthD(int xM, int yM); //helper for breed
	void move();
	void breed();
	void eat(int xM, int yM);
	bool eatRand();
	bool isPrey();
	virtual ~Doodlebug();

private:
	int starvedDoodleBugs;
};

#endif /* DOODLEBUG_H_ */
