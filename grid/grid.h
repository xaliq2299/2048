#ifndef _2048_GRID
#define _2048_GRID

void menu();
//a function to print the rules of a game
int* constructGrid();
//a function that creates and returns an array of size 16
//we behave with this array as 4x4 2d array
void printGrid(int *grid);
//a function that prints the grid in a beautiful way as a table
void destructGrid(int *grid);
//a function that destroys grid
//needed after finishing the game
void copyGrids(int *a1, int *a2);
//a function that copies the contents of array a1 to an array a2
int isTheSame(int *grid1, int *grid2);
//a function that checks the equality of 2 grids
//important for an operation that allows to go to the previous state of a grid
int nbDigits(int n);
//a function that returns #of digits of given integer n
//needed in printing grid
void randomPosition(int *grid);
//a function that will randomly generate 2 or 4 in a random position in a grid
int random2or4();
//a function that decides to put either 2 or 4 as a next random number
int is_Won(int *grid);
//a function that checks whether the user won the game
int is_Lost(int *grid);
//a function that checks whether the user lost the game

#endif
