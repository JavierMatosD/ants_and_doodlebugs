# Ants and Doodlebugs

## Description
This program involves a simulation of a grid of n-by-n squares, some of which may be occupied by organisms. There are two kinds of organisms — doodlebugs (the predators) and ants (the prey). Only one organism may occupy a cell at a time. Time is simulated in steps. Each organism attempts to perform some action every step. No action may cause an organism to move off the edges of the grid.

Ants behave as follows:

	Move. For every step, each ant enumerates its adjacent cells — up, down, left, or right — and randomly selects an unoccupied one that is on the grid (Note: For this assignment, a cell has a maximum of four neighbors; no diagonal moves are allowed). If all adjacent cells are occupied or off the edges of the grid, the ant does not move but rather remains in its current location. 0F 

	Breed. If an ant survives for at least three time steps, at the end of the third time step (i.e., after moving) the ant gives birth to a new ant in an adjacent cell (i.e., up, down, left, or right). If more than one empty cell is available, it chooses one at random. If no empty cell is available, no birth occurs (but the ant is free to try breeding again on the next time step).1F  Once an offspring is produced, an ant cannot produce another offspring until it has survived three additional steps.2F 

Doodlebugs behave as follows:

	Move. For every time step, each doodlebug moves to an adjacent cell containing an ant and eats that ant. If more than one adjacent cell contains an ant, one is chosen at random. The ant that was eaten is removed from the grid. If no adjacent cell (i.e., up, down, left, or right) contains an ant, the doodlebug moves according to the same rules as ants. Note that a doodlebug cannot eat another doodlebug.
	Starvation. If a doodlebug has not eaten an ant within three time steps, at the end of the third time step, it dies of starvation and is removed from the grid.
	Breed. If a doodlebug survives for at least eight time steps, at the end of the eighth time step it spawns off a new doodlebug in the same manner as an ant. If no adjacent cell is empty, no breeding occurs. Once an offspring is produced, a doodlebug cannot produce another offspring until it has survived eight additional steps. Starvation takes precedence over breeding; that is, a starving doodlebug cannot breed.

During each time step, the doodlebugs act before the ants.  That is, a doodlebug may eat an ant that was about to move and possibly to breed; as a result, that ant is dead and can no longer do either.
Remember: If an organism (i.e., an ant or a doodlebug) is eligible to breed but prevented from doing so by virtue of no empty adjacent cells, it remains eligible to breed on the next step.

# Usage

In order to run the simulation, simply clone the repository build the project and run!

You can choose to run the simulation with no arguments or by adding the following: Grid Size, # of Ants, # or Doodle Bugs, # of Steps to run, seed (for rand()), and pause.

NOTE: all arguments are integers and the pause argument is either a 1 or 0.


# Known Issues

1. There us a linking issue on my local machine. As a result, I had to include all the .cpp files within the AntsAndDoodles.cpp file for the program to have access to the other classes. 
   
2. There is a bug that prevents the table from printing the doodlebugs. 

## Authors and Acknowledgment 

Javier Matos - Author <br/>
Professor Ciaraldi - Guidance <br>
Professor Theresa - Guidance