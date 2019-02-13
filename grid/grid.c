#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid.h"

void menu(){
	printf("    =========================================================================\n");
	printf("\033[1;31m");
	printf("%45s\n", "GAME 2048");
	printf("\033[0m");
	printf("    =========================================================================\n\n");
	printf("Rules:\n");
	printf("* You just move your arrow keys"
		   " to double your numbers.\n");
	printf("* Try to get as much higher score as you can and try to get until number 2048.\n");
	printf("* At each movement you have one and only one chance to go to the one step before.\n");
}

int* constructGrid(){
	int *grid = (int*)calloc(16, sizeof(int));
	return grid;
}

int nbDigits(int n){
	int counter = 0;
	while(n != 0){
		counter++;
		n/=10;
	}
	return counter;
}

void printGrid(int *grid){
	printf("┌─────┬─────┬─────┬─────┐\n"); //first line
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(j == 0)	printf("│");
			if(grid[i*4+j] != 0){
				printf("%d", grid[i*4+j] );
				int nb = nbDigits(grid[i*4+j]);
				for(int i=1;i<=5-nb;i++)
					printf(" ");
				
				if(j == 3) printf("│\n");	
				else	   printf("│");	
			}	
			else{
				printf("     ");
				if(j == 3) printf("│\n");	
				else	   printf("│");	
			}
		}
		if(i == 3)
			printf("└─────┴─────┴─────┴─────┘\n"); //last line
		else	
			printf("├─────┼─────┼─────┼─────┤\n"); //mid line
	}
}

void copyGrids(int *a1, int *a2){
	for(int i=0;i<16;i++)
		a2[i] = a1[i];
}

int isTheSame(int *grid1, int *grid2){
	for(int i=0;i<16;i++){
		if(grid1[i] != grid2[i])
			return 0;
	}
	return 1;
}

void destructGrid(int *grid){
	free(grid);
}

void randomPosition(int *grid){
	srand(time(NULL));
	while(1){
		int position = rand()%16;
		if( grid[position] == 0 ){
			grid[position] = random2or4();
			break;
		}
		else
			continue;
	}
}

int random2or4(){
	int probability[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1};
	if( probability[rand()%100] % 2 == 0 )	return 2;
	else return 4;
}

int is_Won(int *grid){
	int big = grid[0];
	
	for(int i=1;i<16;i++){
		if(grid[i] > big)
			big = grid[i];
	}
	if(big == 2048)
		return 1;
	else
		return 0;
}

int is_Lost(int *grid){
	for(int i=0;i<16;i++){
		if(grid[i] == 0) 
			return 0;
	}
	if(grid[0] != grid[1] && grid[1] != grid[2] && grid[2] != grid[3] && grid[4] != grid[5] &&
	  grid[5] != grid[6] && grid[6] != grid[7] && grid[8] != grid[9] && grid[9] != grid[10] &&
	  grid[10] != grid[11] && grid[12] != grid[13] && grid[13] != grid[14] && grid[14] != grid[15]
	  && grid[0] != grid[4] && grid[4] != grid[8] && grid[8] != grid[12] && grid[1] != grid[5] &&
	  grid[5] != grid[9] && grid[9] != grid[13] && grid[2] != grid[6] && grid[6] != grid[10] &&
	  grid[10] != grid[14] && grid[3] != grid[7] && grid[7] != grid[11] && grid[11] != grid[15])
		return 1;
	else
		return 0;
}