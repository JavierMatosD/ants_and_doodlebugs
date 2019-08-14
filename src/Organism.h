/*
 * Organism.h
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
class Grid;
class Organism {

	friend class Grid;

protected:
	Grid *myGrid;
	int x;
	int y;
	int count;
	int gridSize;
	bool moved;


public:
	Organism();
	Organism(Grid *myGrid, int x, int y, int gridSize);
	virtual bool isPrey() = 0;
	virtual void move()=0;
	virtual void breed()=0;
	virtual bool starving()=0;
    bool canMove();
	//void setAmAnt(bool b);
	virtual ~Organism();
};

#endif /* ORGANISM_H_ */
