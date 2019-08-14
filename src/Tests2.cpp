/*
 * Tests2.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Tests2.h"
#include "Grid.h"
#include "Organism.h"
#include "Ant.h"
#include <iostream>
#include <cstdlib>

Tests2::Tests2() {
	// TODO Auto-generated constructor stub
	//initialize the grid
}

bool Tests2::doTests()
{
	bool results;
	//establish a grid EMPTY
	bool ok1 = gridTest();
	//populate it with ants
	bool ok2 = makeAntsTest();
	//see whether they move
	//bool ok3 = antsMoveTest();
	//see whether they breed
	bool ok4 = antsBreedTest();
	//see whether they die?
	bool ok5 = antsDieTest();//maybe if they wander off?
	//populate with doodlebugs
	bool ok6 = makeDoodlesTest();
	//see whether they move
	bool ok7 = doodleMoveTest();
	//see whether they breed
	bool ok8 = doodleBreedTest();
	//see whether they eat ants
	bool ok9 = doodleEatTest();
	//see whether they die
	bool ok10 = doodleDietest();

	bool ok11 = canMoveTest();

	results = ok1 && ok2 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11;
	if(results){
	cout<<"All test passed"<<endl;
	}
	cout<<"Test failed"<<endl;
	return results;
}
/**
 * gridTest()
 * tests that the grid populates
 * Function utilized the printGrid method as well as the ant contructor
 * @return true (the only way to verify it works is to see the grid)
 *
 */
bool Tests2::gridTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	Ant* testAnt = new Ant();
	std::cout << "Running the grid test: EMPTY GRID" << std::endl;
	Grid myGrid = Grid(0, 20, 0,0);
//	Grid* ptr = myGrid;
	myGrid.printGrid();

	std::cout << "second grid test: tests the setOrganism function with an ANT" << std::endl;
	myGrid.setOrganism(testAnt, 2, 3);
	if(myGrid.getOrganism(2, 3) == NULL)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}

	myGrid.printGrid();

result = ok1 && ok2;
if(result){
	cout<<"gridTest Successful"<<endl;
}
	return result;
}
/**
 * makeAntsTest
 * testing various things
 * functions tests the set Organism function
 * the ant constructors and the isPrey function
 * @return true if Ant() getOrganism and isPrey() all function appropriatly
 */
bool Tests2::makeAntsTest()
{
	bool result = false;
	bool ok1 = false;
	bool ok2 = false;
	std::cout << "Running the make ants test" << std::endl;
	Grid myGrid = Grid(0, 20, 0,0); //create grid
	Ant* testAnt = new Ant(); //create ant
	myGrid.setOrganism(testAnt, 2, 3); //place ant
if(myGrid.getOrganism(2,3)->isPrey()){ //check if ant is there
	ok1 = true;
	ok2 = true;
}

	result = ok1 && ok2;
	if(result)
		cout<<"makeAntsTest successful"<<endl;
	return result;
}
/**
 * testing canMove()
 * test whether an ant can move
 * @return true or false
 */
bool Tests2::canMoveTest(){
	cout<<"running canMoveTest"<<endl;
	bool ok = false;
	Grid myGrid = Grid(0, 20, 0,0); //create grid
	Grid* ptr = &myGrid;
	Ant myAnt = Ant(ptr,0,0,20);
	ok = myAnt.canMove();

	if(ok)
		cout<<"canMoveTest successful"<<endl;
	else cout<<"canMoveTest unsuccessful"<<endl;

	return ok;
}

/**
 * antsMove test()
 * @param void NONE
 * move function moves the ants to a random location, function checks the previous location to ensure it is NULL
 * @return true or false (returns true if the ant moved to the correct location)
 */
bool Tests2::antsMoveTest()
{
	std::cout << "Running the antsMoveTest" << std::endl;
	//bool ok = false;
//	bool result = ok;
	Grid myGrid = Grid(1, 20, 0,0); //create grid
	Grid* ptr = &myGrid;
	Ant myAnt = Ant(ptr,0,0,20);; //place ant
	cout<<"first location"<<endl;
	myGrid.printGrid();
	cout<<"moved location"<<endl;
	//myGrid.antsMove();                  //move ant
	///myGrid.printGrid();
	if(myGrid.getOrganism(0, 0) == NULL){ //check previous location
			//ok = true;
			cout<<"antsMoveTest successful"<<endl;
	}
	cout<<"anstMoveTest unsuccessful"<<endl;

	return true;
}
bool Tests2::antsBreedTest()
{
	bool result = true;
	std::cout << "Running the breed ants test" << std::endl;
	return result;
}
bool Tests2::antsDieTest()
{
	bool result = true;
	std::cout << "Running the ants die test" << std::endl;
	return result;
}
bool Tests2::makeDoodlesTest()
{
	bool result = true;
	std::cout << "Running the make doodlebugs test" << std::endl;
	return result;
}
bool Tests2::doodleMoveTest()
{
	bool result = true;
	std::cout << "Running the move doodlebugs test" << std::endl;
	return result;
}
bool Tests2::doodleBreedTest()
{
	bool result = true;
	std::cout << "Running the breed doodlebugs test" << std::endl;
	return result;
}
bool Tests2::doodleEatTest()
{
	bool result = true;
	std::cout << "Running the eat ant test" << std::endl;
	return result;
}
/**
 * doodleDieTest
 * tests the doodBugStarve method
 * @param void NONE
 * return true or false(true if the doodlebug starved false otherwise)
 */
bool Tests2::doodleDietest()
{
	std::cout << "Running the doodlebug dies test" << std::endl;
	bool result = false;
	Grid myGrid = Grid(0, 20, 0,0); //create grid
	Doodlebug* testDoodle = new Doodlebug(); //create doodlebug
	myGrid.setOrganism(testDoodle, 2, 3); //place doodlebug
	//move the doodlebug three consecutive spaces
	testDoodle->move();
	testDoodle->move();
	testDoodle->move();
	myGrid.doodleBugStarve();

	if(myGrid.getOrganism(2, 3) == NULL){
	 result = true;
	 cout<<"doodleDieTest successful"<<endl;
	}
	else cout<<"doodleDieTest unsuccessful"<<endl;

	return result;
}

Tests2::~Tests2() {
	// TODO Auto-generated destructor stub
}

