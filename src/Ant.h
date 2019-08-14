/*
 * Ant.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"
#include "Grid.h"
#include <iostream>

class Ant: public Organism {

public:
	Ant();
	Ant(Grid *myGrid, int x, int y, int gridSize);
	void move();
	void breed();
	bool starving();
	void birth(int x, int y);
	bool isPrey();

	 ~Ant();
};

#endif /* ANT_H_ */
