/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */
#include <cstdlib>
#include "Ant.h"
#include <iostream>


/**
 * constructor for ANT
 * @param void NONE
 * @return void NONE
 */
Ant::Ant() :Organism(){}
/**
 * constructor for an ANT
 * @param *myGrid pointer to the grid
 * @param int x coordinate
 * @param int y coordinate
 * @param int gridSize (size of one side of the grid space)
 * @return void NONE
 */
Ant::Ant(Grid *myGrid, int x, int y, int gridSize):Organism(myGrid, x, y, gridSize){}

void Ant::move(){

	count++; //an ant can only move if it has survived a step in simulation

	int direction = 0; //direction the ant will move in

	if(canMove()){
		do{
			direction = (rand()%4) +1;
			switch(direction){
			case 1:
				if((x < gridSize - 1) && (myGrid->getOrganism(x + 1 , y)==NULL)){
					myGrid->setOrganism(myGrid->getOrganism(x,y), x + 1, y);
					myGrid->setOrganism(NULL, x, y);
					x++;
				}
				break;
			case 2:
				if((x > 0) && (myGrid->getOrganism(x - 1, y)==NULL)){
					myGrid->setOrganism(myGrid->getOrganism(x,y), x-1,y);
					myGrid->setOrganism(NULL,x,y);
					x--;
				}
				break;
			case 3:
				if((y < gridSize -1) && (myGrid->getOrganism(x, y+1)==NULL)){
					myGrid->setOrganism(myGrid->getOrganism(x,y), x, y+1);
					myGrid->setOrganism(NULL,x,y);
					y++;
				}
				break;
			case 4:
				if((y > 0) && (myGrid->getOrganism(x, y-1)==NULL)){
					myGrid->setOrganism(myGrid->getOrganism(x,y), x, y-1);
					myGrid->setOrganism(NULL,x,y);
					y--;
				}
				break;

			}
		}while(!moved);
	}
}
/**
 * isPrey
 * (and ANT is a prey)
 * @param void NONE
 * @return True
 */
bool Ant::isPrey(){
	return true;
}
/**
 * starving()
 * returns false
 * @param void NONE
 * @return False
 */

bool Ant::starving(){
	return false;
}
/**
 * birth()
 * Helper for breed function
 * @param int x coordinate
 * @param int y coordinate
 * @return
 */
void Ant::birth(int newX, int newY){
	new Ant(myGrid,x+newX,y +newY, gridSize);
	count = 0;
	myGrid->setAntNum(myGrid->getNumAnts()+1);
}
/**
 * breed()
 * function for breed for ants
 * @param void NONE
 * @return void NONE
 */
void Ant::breed()
{
	int breedHere = 0;
	if((count >= 3) && canMove()){
		do{
			breedHere = (rand()%4)+1;

			switch(breedHere){
			case 1:
				if((x < gridSize -1) && (myGrid->getOrganism(x+1,y) ==NULL)){
					birth(1,0);
				}
				break;
			case 2:
				if((x > 0) && (myGrid->getOrganism(x-1,y) ==NULL)){
					birth(-1,0);
				}
				break;
			case 3:
			if((y < gridSize -1) && (myGrid->getOrganism(x,y+1) ==NULL)){
				birth(0,1);
			}
				break;
			case 4:
				if((y > 0) && (myGrid->getOrganism(x,y-1) ==NULL)){
					birth(0,-1);
				}
				break;

			}
		}while(count != 0);
	}
}

Ant::~Ant() {}

