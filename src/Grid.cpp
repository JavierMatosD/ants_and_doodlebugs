/*
 * Grid.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Grid.h"
#include "Cell.h"

using std::string;

using namespace std;

int n=0; //this initial value will be changed when the program is invoked
Cell** myGridCells_ptr_array = (Cell**)nullptr;
/**
 * Default Constructor
 * @param None
 * @return None
 */
Grid::Grid() {
	   //Default to 0
	     gridSize = 0;
		 ants = 0;
		 doodleBugs = 0;
		 antBirthsSuccesful = 0;
		 antBirthsTotal=0;
		 doodleBugBirthsSuccesful = 0;
		 doodleBugBirthsTotal=0;
		 steps=0;
		 myGrid = NULL;
}
/*
Grid::Grid(int nSquaresOnASide)
{
	n = nSquaresOnASide; //initialize size of grid
	//we do not want automatic storage for the grid

	myGridCells_ptr_array = new Cell* [n];  //first allocate array of row pointers

	for(int i=0 ; i < n ; i++)
	{
		myGridCells_ptr_array[i] = new Cell[n]; // allocate memory for columns in each row
	}
}
*/
/**
 * Grid(Parmetized)
 * Parametized constuctor for a Grid
 * @param Unsigned int Iseed for srand()
 * @param int arraySize size of grid
 * @param int liveAnts
 * @param int liveDoodleBugs
 * @return void NONE
 */

Grid::Grid(unsigned int seed, int arraySize, int liveAnts, int liveDoodleBugs){

	doodleBugs = liveDoodleBugs;
	ants = liveAnts;
	gridSize = arraySize;
	antBirthsTotal=0;
	antBirthsSuccesful = 0;
	doodleBugBirthsSuccesful = 0;
	doodleBugBirthsTotal=0;
	steps=0;
	//if seed is 0
   //set system time to current
	if(seed == 0)
		srand(time(0));

	myGrid = (Organism***)malloc(gridSize*sizeof(Organism**));

	int i;
	int j;
	//initialize myGrid to NULL
	for(i =0; i < gridSize; i++){
		myGrid[i] = (Organism **)malloc(gridSize*sizeof(Organism*));
		for(j = 0; j<gridSize; j++)
			{
				myGrid[i][j] = NULL;
			}
	}
	//populate grid
	string ant = "Ant";
	string doodlebug = "Doodlebug";

	placeOrganisms(ant, ants);
	placeOrganisms(doodlebug, doodleBugs);


}


/**
 * setOrganism()
 * @param *organism pointer to organism
 * @param int x coordinate
 * @param int y coordinate
 */
void Grid::setOrganism(Organism *organism, int x, int y)
{
	if(withinRange(x,y)){
		myGrid[x][y] = organism;

	}
}
/**
 * withinRange
 * @param int x coordinate
 * @param int y coordinate
 * @return true if coordinates are within the grid false otherwise
 */
bool Grid::withinRange(int x, int y)
{
	return ((x >= 0) && (x < gridSize) && (y >= 0) && (y < gridSize));
}
/**
 * getOrganism()
 * returns a pointer to the Organism
 * @param int x
 * @param int y
 * @return void NONE
 * MAY RETURN NULL IF COORDINATES ARE INVALID
 */
Organism *Grid::getOrganism(int x, int y)
{
	//check if x, y are within myGrid
	if(withinRange(x,y))
		return myGrid[x][y];

	//NULL return indicative of invalid coordinates
	else return NULL;
}
/**
 * randomPlace
 * returns a random x or y coordinate
 * @param void NONE
 * @param int random num
 */
int Grid::randomPlace(){
	return (rand() % gridSize);
}
/**
 * placeOrganisms()
 * @param string type of orgaism to spawm
 * @param int count (number of said type to spawn)
 */
void Grid::placeOrganisms(string organism, int count){
	int x = 0;
	int y = 0;
	int runningCount = 0;
//while the counter is less than than the count given
	while (runningCount < count){
		x = randomPlace();
		y = randomPlace();
		//check if location is NULL
		if(myGrid[x][y] == NULL){
			if(organism.compare("Ant") == 0){
				new Ant(this,x, y, gridSize);
				runningCount++;

			}else if(organism.compare("Doodlebug")==0){
				new Doodlebug(this, x, y,  gridSize);
				runningCount++;
			}
		}
	}
}
/**
 * printGrid
 * prints the grid to terminal
 * @param void NONE
 * @return void NONE
 */
void Grid::printGrid(){
	int i;
	int j;
	//i(number of rows)
	//j(number of columns)
	for (i = 0; i < gridSize; i++)
	{
		for (j = 0; j < gridSize; j++)
		{
			if(myGrid[i][j] == NULL)
				cout<<"-"; //EMPTY
			else if(myGrid[i][j]->isPrey())
			{cout<<"o";} //ANT

			else if(!myGrid[i][j]->isPrey())
				{cout<<"x";} //DOODLEBUG
		}
		cout<<endl;
	}

}
/**
 * antsMove()
 * moves the ants
 * @param void NONE
 * @return void NONE
 */
void Grid::antsMove(){
	int i;
	int j;

	for(i =0; i<gridSize; i++){
		for (j =0; j <gridSize; j++){
			//if it is an ANT
			if ((myGrid[i][j] != NULL) && (myGrid[i][j]->isPrey())){
				//check if it hasn't
				if(myGrid[i][j]->moved == false){
					//set moved status to true and move
					myGrid[i][j]->moved = true;
					myGrid[i][j]->move();
				}
			}
		}
	}
}
/**
 * doodleBugsMove()
 * move the doodleBugs
 * @param void NONE
 * @return void NONE
 */
void Grid::doodleBugsMove(){
	int i;
	int j;

	for(i =0; i<gridSize; i++){
		for (j =0; j <gridSize; j++){
				//if it is doodleBug
			if ((myGrid[i][j] != NULL) && !(myGrid[i][j]->isPrey())){
				//check if it hasn't
				if(myGrid[i][j]->moved == false){
					//set moved status to true and move
					myGrid[i][j]->moved = true;
					myGrid[i][j]->move();
				}
			}
		}
	}
}
/**
 * resetM
 * rests the recently moved value of organisms
 * @param void NONE
 * @return void NONE
 */
void Grid::resetM(){
int i;
int j;
for (i =0; i<gridSize; i++){
	for (j=0;j<gridSize;j++){

		if(myGrid[i][j] != NULL)
			myGrid[i][j]->moved = false;

	}
}
}
/**
 * doodleBugStarve()
 * kills all starving doodlebugs
 * @param void NONE
 * @return void NONE
 */
void Grid::doodleBugStarve(){
	int i;
	int j;

for(i = 0; i<gridSize; i++){
	for (j =0; j<gridSize; j++){
		//is doodleBug is starving KILL
		if(myGrid[i][j] !=NULL && !myGrid[i][j]->isPrey() && myGrid[i][j]->starving()){
			delete myGrid[i][j]; //KILL
			myGrid[i][j] = NULL; //reset to NULL
			doodleBugs --; //decrease total doodleBUGS
		}
	}
}
}
/**
 * breedAnts()
 * breeds all eligible ants
 * @param void NONE
 * @return void NONE
 */

void Grid::breedAnts(){
	int i;
	int j;
	int beforeAnts = ants;

	for (i =0; i < gridSize; i++){
		for (j=0;j < gridSize; j++){
			if(myGrid[i][j] != NULL && myGrid[i][j]->isPrey() && myGrid[i][j]->moved == true){
				myGrid[i][j]->breed();
			}
		}
	}
	antBirthsSuccesful = ants - beforeAnts;
	antBirthsTotal += antBirthsSuccesful;
}

/**
 * breedDoodlebugs
 * breeds the doodlebugs
 * @param void NONE
 * @@return void NONE
 */
void Grid::breedDoodlebugs(){
	int i;
	int j;
	int beforeDoodle = doodleBugs;

	for (i = 0; i <gridSize ; i++){
		for (j=0;j<gridSize ; j++){
			if(myGrid[i][j] != NULL && myGrid[i][j]->moved == true && !myGrid[i][j]->isPrey()){
				myGrid[i][j]->breed();
			}
		}
	}
	doodleBugBirthsSuccesful = doodleBugs - beforeDoodle;
	doodleBugBirthsTotal+= doodleBugBirthsSuccesful;
}
/**
 * step()
 * one time step in the game
 * @param void NONE
 * @param void NONE
 */
void Grid::step(){
	resetM();
	doodleBugsMove();
	antsMove();
	doodleBugStarve();
	breedDoodlebugs();
	breedAnts();
	steps++;
}
/**
 * shows the game stats
 * @param void NONE
 * @param void NONE
 */

void Grid::termination(){
	printGrid();
	cout<<"Doodlebugs on the prowl: "<<doodleBugs<<endl;
	cout<<"Surviving Ants: "<<ants<<endl;
	cout<<"Total number of ants: "<<ants + antBirthsTotal<<endl;
	cout<<"Total number of doodleBugs: "<<doodleBugs + doodleBugBirthsTotal<<endl;
}
Grid::~Grid()
{
int i;
int j;
for (i = 0; i < gridSize; i++){
		for(j=0; j < gridSize; j++){
			if(myGrid[i][j] != NULL){
				delete(myGrid[i][j]);
			}
		}
}
free(myGrid);
}

