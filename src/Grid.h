/*
 * Grid.h
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#ifndef GRID_H_
#define GRID_H_

#include "Cell.h"
#include "Ant.h"
#include "Doodlebug.h"
#include "Organism.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

using std::string;
using namespace std;

class Grid {
private:

//in game variables / Fields
	int doodleBugs;
	int ants;
	int gridSize;
	int antBirthsTotal;
	int antBirthsSuccesful;
	int doodleBugBirthsSuccesful;
	int doodleBugBirthsTotal;
	int steps;
	Organism ***myGrid;

public:

	Grid();
	//Grid(int nSquaresOnASide);
	Grid(unsigned int seed, int gridSize, int liveAnts, int liveDoodleBugs);


	//getters and setters
	void setAntNum(int liveAnts){
		ants = liveAnts;
	}
	int getNumAnts(){
		return ants;
	}

	void setDoodleBugs(int liveDoodleBugs){
		doodleBugs = liveDoodleBugs;
	}
	int getNumDoodleBugs(){
		return doodleBugs;
	}
	int getAntBirthsTotal(){
		return antBirthsTotal;
	}
	int getDoodleBugsBirthsTotal(){
		return doodleBugBirthsTotal;
	}

	void setOrganism(Organism *organism, int x, int y);
	Organism *getOrganism(int x, int y);
	void placeOrganisms(string Organism, int organismCount);

	//HELPERS

	int randomPlace();
	bool withinRange(int x, int y);
	void printGrid();
	void step();
	void termination();
	void everyOneBreed();
	void breedAnts();
	void breedDoodlebugs();
	void doodleBugStarve();
	void antsMove();
	void doodleBugsMove();
	void resetM();


	//DESTRUCTOR
	virtual ~Grid();
};

#endif /* GRID_H_ */
