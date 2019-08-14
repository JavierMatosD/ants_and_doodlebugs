/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#include "Doodlebug.h"
//#include "Organism.h"
#include <iostream>
#include <cstdlib>

/**
 * constructor for doodlebug
 * @param void NONE
 * @return void NONE
 */
Doodlebug::Doodlebug() :Organism(){starvedDoodleBugs = 0;}
/**
 * constructor for doodlebug
 * @param Grid* myGrid pointer to a grid
 * @param int x coordinate
 * @param int y coordinate
 * @param int gridSize (size of grid)
 * @return void NONE
 */
Doodlebug::Doodlebug(Grid* myGrid, int x, int y, int gridSize) : Organism(myGrid, x, y, gridSize){starvedDoodleBugs = 0;}
/**
 *move()
 *moves doodlebugs
 *@param void NONE
 *@param void NONE
 *@return void NONE
 */
void Doodlebug::move()
{
	count++;
	int direction =0;
	if(eatRand()){return;}
	else{starvedDoodleBugs++;}

	if(canMove()){
		do{
			direction = (rand()%4+1);

			switch(direction){
			case 1: //RIGHT
				if((x<gridSize-1)&&(myGrid->getOrganism(x+1, y) == NULL)){

					myGrid->setOrganism(myGrid->getOrganism(x, y), x+1, y);
					myGrid->setOrganism(NULL, x, y);
					x++;
				}
				break;
			case 2: //LEFT
				if((x>0)&&(myGrid->getOrganism(x-1, y) == NULL)){

						myGrid->setOrganism(myGrid->getOrganism(x, y), x-1, y);
						myGrid->setOrganism(NULL, x, y);
						x--;
				}
				break;
			case 3: //UP
					if((y<gridSize-1)&&(myGrid->getOrganism(x, y+1) == NULL)){

						myGrid->setOrganism(myGrid->getOrganism(x, y), x, y+1);
						myGrid->setOrganism(NULL, x, y);
						y++;
				}
				break;
			case 4: //DOWN
					if((y>0)&&(myGrid->getOrganism(x, y-1) == NULL)){

						myGrid->setOrganism(myGrid->getOrganism(x, y), x, y-1);
						myGrid->setOrganism(NULL, x, y);
						y--;
				}
				break;
			}
		}while(!moved);
	}
}
/**
 * breed()
 * breeds doodlebugs
 * @param void NONE
 * @return void NONE
 */
void Doodlebug::breed()
{
	int breedHere = 0;
	if((count >= 8) && !(starving()) && (canMove())){
		do{
			breedHere = (rand()%4 +1);
			switch(breedHere){
		case 1: //RIGHT
			if((x<gridSize-1)&&(myGrid->getOrganism(x+1, y) == NULL)){birthD(1,0);}
			break;

		case 2: //LEFT
			if((x>0)&&(myGrid->getOrganism(x-1, y) == NULL)){birthD(-1,0);}
			break;

		case 3: //UP
			if((y<gridSize-1)&&(myGrid->getOrganism(x, y+1) == NULL)){birthD(0,1);}
			break;

		case 4: //DOWN
			if((y>0)&&(myGrid->getOrganism(x, y-1) == NULL)){birthD(0,-1);}
			break;
			}
		}while(count != 0);
	}
}
/**
 * birthD
 * helper for breed
 * @param int x coordinate (where the new doodlebug will be placed)
 * @param int y coordinate (where the new doodlebug will move to)
 * @return void NONE
 */

void Doodlebug::birthD(int xM, int yM){
	//create doodlebug
	new Doodlebug(myGrid, (x + xM), (y + yM), gridSize);
	count=0; //set counter for current to 0
	myGrid->setDoodleBugs(myGrid->getNumDoodleBugs()+1); //reset doodlebug count
}
/**
 * eat()
 * eats an ant in specific coordinate
 * @param int xM (where you want the doodlebug to move in x direction)
 * @param int yM (where you want the doodlebuf to move in the y direction)
 * @return void NONE
 */
void Doodlebug::eat(int xM, int yM){
	//delete ant in given coordinate and update ant number and doodle bug starve count ie starvedDoodleBugs
	delete myGrid->getOrganism(x + xM, y + yM);
	myGrid->setAntNum(myGrid->getNumAnts()-1);
	starvedDoodleBugs = 0;

	//update where doodlebug moved too
	myGrid->setOrganism(myGrid->getOrganism(x, y), x +xM, y + yM);

	//set the previous location to NULL
	myGrid->setOrganism(NULL, x, y);

	//update the doodleBugs coordinates ie x and y
	//x coordinate
	if(xM ==1 ) {x++;}
	if(xM ==-1) {x--;}
	//y coordinate
	if(yM ==1 ) {y++;}
	if(yM ==-1) {x--;}

}
/**
 * eatRand()
 * if there checks if it can eat and if more than one option available then picks a random
 * @param void NONE
 * @return true (if it ate) or false (if it did not)
 */
bool Doodlebug::eatRand(){
	//set up bool values for up, down, left and right
	bool up    = false;
	bool down  = false;
	bool left  = false;
	bool right = false;

	//check for ants in surrounding cells

	//checking the right cell
	if  ((x < gridSize - 1) &&
		(myGrid->getOrganism(x + 1, y) != NULL) &&
		(myGrid->getOrganism(x+1, y)->isPrey()))   {right = true;}

	//checking the left cell

	if  ((x > 0) &&
		(myGrid->getOrganism(x-1,y) != NULL) &&
		(myGrid->getOrganism(x-1, y)->isPrey()))   {left = true;}

	//checking up

	if  ((y < gridSize - 1) &&
			(myGrid->getOrganism(x,y+1) != NULL) &&
			(myGrid->getOrganism(x, y+1)->isPrey()))   {up = true;}

	//checking down
	if  ((y > 0) &&
			(myGrid->getOrganism(x,y-1) != NULL) &&
			(myGrid->getOrganism(x, y-1)->isPrey()))   {down = true;}

	//potential coordinates for doodlebug movement
	int xDM = 0;
	int yDM = 0;

	//four different possibilities
	//P1: there is only one options
	//P2: there are two options
	//P3: there are three options
	//P4: there are four options

	//P1:

	//UP only
	if(up && !(left && right && down)){eat(0,1);}

	//DOWN only
	if(down &&!(left && up && right)){eat(0,-1);}

	//RIGHT only
	if(right &&!(left && up && down)){eat(1,0);}

	//LEFT only
	if(left &&!(right && up && down)){eat(-1,0);}

	//P2

	//RIGHT and UP

	if((right && up) && !(left&&down)){
		//diagonal eating not allowed
		while(xDM == yDM){
			//randomize xDM and yDM
			xDM = (rand() > RAND_MAX/2)? 0:1;
			yDM = (rand() > RAND_MAX/2)? 0:1;
		}
		eat(xDM, yDM);
	}
	//LEFT and UP
	if((left && up) && !(right&&down)){
		//diagonal eating not allowed
		while(xDM == yDM){
			//randomize xDM and yDM
			xDM = (rand() > RAND_MAX/2)? -1:0;
			yDM = (rand() > RAND_MAX/2)? 0:1;
		}
		eat(xDM, yDM);
	}
	//LEFT and DOWN
	if((left && down) && !(right&&up)){
		//randomize xDM and yDM
		while(xDM == yDM){
			xDM = (rand() > RAND_MAX/2)? -1:0;
			yDM = (rand() > RAND_MAX/2)? -1:0;
		}
		eat(xDM, yDM);
	}
	//RIGHT and DOWN
	if((right && down) && !(left&&up)){
		//randomize xDM and yDM
		while(xDM == yDM){
			xDM = (rand() > RAND_MAX/2)?  0:1;
			yDM = (rand() > RAND_MAX/2)? -1:0;
		}
		eat(xDM, yDM);
	}

	//P3

	//RIGHT, UP, DOWN

	if((up&&down&&right)&& !(left)){
		//randomize xDM and yDM
			while(xDM == yDM){
				xDM = (rand() > RAND_MAX/2)?  0:1;
				yDM = (rand() > RAND_MAX/2)? -1:1;
			}
			eat(xDM, yDM);
		}

	//LEFT, UP, DOWN

	if((up&&down&&left)&& !(right)){
		//randomize xDM and yDM
			while(xDM == yDM){
				xDM = (rand() > RAND_MAX/2)?  -1:0;
				yDM = (rand() > RAND_MAX/2)? -1:1;
			}
			eat(xDM, yDM);
		}
	//LEFT, RIGHT, DOWN

	if((right&&down&&left)&& !(up)){
		//randomize xDM and yDM
			while(xDM == yDM){
				xDM = (rand() > RAND_MAX/2)?  -1:1;
				yDM = (rand() > RAND_MAX/2)? -1:0;
			}
			eat(xDM, yDM);
		}
	//LEFT, RIGHT, UP

	if((right&&up&&left)&& !(down)){
		//randomize xDM and yDM
			while(xDM == yDM){
				xDM = (rand() > RAND_MAX/2)?  -1:1;
				yDM = (rand() > RAND_MAX/2)? 0:1;
			}
			eat(xDM, yDM);
		}

	//P4

	//EVERYTHING IS AVAILABLE

	if((up&&down&&left&&right)){
		//randomize xDM and yDM
		while(xDM == yDM){
			xDM = (rand() > RAND_MAX/2)? -1:1;
			xDM = (rand() > RAND_MAX/2)? -1:1;
		}
		eat(xDM, yDM);
	}


	if(up|| down || left || right)
		return true;
	else
		return false;

}


/**
 * isPrey
 * @param void NONE
 * @return void NONE
 */
bool Doodlebug::isPrey(){
	return false;
}
/**
 * starving()
 * @param void NONE
 * @return True of False (true if doodlebug hasnt eaten in three steps)
 */
bool Doodlebug::starving(){
	if(starvedDoodleBugs == 3)
		return true;
	else
		return false;
}

Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

