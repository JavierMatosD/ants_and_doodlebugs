/*
 * Production.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Production.h"
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include "Grid.h"
#include <conio.h>
#include <string>

using namespace std;

int timestepsLeft=100;

//initial arguments (Default)
	int gridSize = 20;
	int ants = 100;
	int doodleBugs = 5;
	int timeSteps = 1000;
	unsigned int seed = 1; //for rand()
	int pause = 0;
	string keystroke; //to check for pause argument


/**
 * Production function
 * @param argc Number of words on the command line
 * @parama argv Array of pointers to character strings (contains the paramaters for simulation)
 * @return void NONE
 */
Production::Production(int argc, char* argv[]) {

	//checking input arguments
	if(argc > 1)
	{
		gridSize = atoi(argv[1]);
	}
	//if arguments are found replace defaults
	if(argc > 2)
	{
		doodleBugs = atoi(argv[2]);
	}

	if(argc >3 )
	{
		ants = atoi(argv[3]);
	}
	if(argc > 4)
	{
		timeSteps= atoi(argv[4]);
	}

	if(argc > 5)
	{
		seed = atoi(argv[5]);
	}
	else if (atoi(argv[5]) == 0)
			{
		seed = 0;
			}
	if(argc > 6 || ((argv[6] != NULL) && (argv[6] >= 0)))
		{
			pause = atoi(argv[6]);
		}
}

bool Production::runProduction()
{
	//checks if the number of organism would overflow the grid
			if((ants + doodleBugs) > (gridSize * gridSize))
			{
				//print ERROR
				cout<<"Too Many Organisms for size of grid"<<endl;
				return EXIT_FAILURE;
			}

			Grid grid(seed, gridSize, ants, doodleBugs);

			int count = 1;


	bool ok = false;
	bool haspause  = false;
	while(count <= timeSteps)
	{
		if(haspause){
			cout<<"Time Step: "<<count<<endl;
			grid.printGrid();
			cout<<"Enter key to continue:"<<count<<endl;
			getline(cin,keystroke);
		}
		if((pause >= 0) && (pause == count) && !haspause){

			cout<<endl<<"Time Step: "<<count<<endl;
			grid.printGrid();
			cout<<endl<<"Enter character to continue"<<endl;
			getline(cin,keystroke);
			haspause = true;
		}

		grid.step();
		count++;

		if((grid.getNumAnts() == 0) ||(grid.getNumDoodleBugs() == 0) || (count == timeSteps)){
			cout<<endl<<"Time Steps: "<<count<<endl;
			cout<<endl<<"Line Arguments: "<<gridSize<< " "<<ants<< " "<<doodleBugs<<" "<<timeSteps<< " "<<seed<<" "<<pause<<endl;
			grid.termination();
			//grid.printGrid();
			ok =true;

		}
	}
	cout<<"Production Ran"<<endl;
    return ok;
}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

