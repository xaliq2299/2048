#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "movements.h"

#include <termios.h>

#include <unistd.h>
#include <assert.h>
#include <string.h>

#define LOSE 0
#define WIN 1
#define CONTINUE 2

int _getch(void) {
      int c=0;

      struct termios org_opts, new_opts;
      int res=0;
          //-----  store old settings -----------
      res=tcgetattr(STDIN_FILENO, &org_opts);
      assert(res==0);
          //---- set new terminal parms --------
      memcpy(&new_opts, &org_opts, sizeof(new_opts));
      new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
      tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
      c=getchar();
          //------  restore old settings ---------
      res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
      assert(res==0);
      return(c);
}

int main(){
	FILE *fp = fopen("bestScore.txt", "r");
	int totalScore = 0, score, bestScore, steps = 0, status, changeInGrid;
	fscanf(fp, "%d", &bestScore); fclose(fp);
	int *grid, *previousGrid;
	int movement; // can be left(37), up(38), right(39), down(40)
	menu();						    // welcome and the rules of a game
	grid = constructGrid();         // creating grid
	previousGrid = constructGrid(); // needed to be able to return to the state one step before
	randomPosition(grid);
	randomPosition(grid);
	printGrid(grid);
	while(1){
		movement = _getch();
		if(movement == 65) {
			score=0;
			copyGrids(grid, previousGrid);
			changeInGrid = up(grid, &totalScore, &score); 
			if(changeInGrid != 0){
				randomPosition(grid);
				steps++;
			}
		}
		else if(movement == 66){
			score=0;
			copyGrids(grid, previousGrid);
			changeInGrid = down(grid, &totalScore, &score);
			if(changeInGrid != 0){
				randomPosition(grid);
				steps++;
			}
		}
		else if(movement == 67){
			score=0;
			copyGrids(grid, previousGrid);
			changeInGrid = right(grid, &totalScore, &score);
			if(changeInGrid != 0){
				randomPosition(grid);
				steps++;
			}
		}
		else if(movement == 68){
			score=0;
			copyGrids(grid, previousGrid);
			changeInGrid = left(grid, &totalScore, &score);
			if(changeInGrid != 0){
				randomPosition(grid);
				steps++;
			}
		}
		else if(movement == 112){
			if( !isTheSame(grid, previousGrid) ){
				copyGrids(previousGrid, grid);
				steps--;
				totalScore -= score;
			}
		}

		system("clear");
		if(totalScore < bestScore)
			printf("STEPS : %d\tSCORE : %d\tBEST SCORE: %d\n", steps, totalScore, bestScore);
		else
			printf("STEPS : %d\tSCORE : %d\tBEST SCORE: %d\n", steps, totalScore, totalScore);
		printGrid(grid);
	
		if(is_Lost(grid))     { status = LOSE; break; }
		else if(is_Won(grid)) { status = WIN;  break; }
		else                  { status = CONTINUE; continue; }	
	}
	if(totalScore >= bestScore){ fp = fopen("bestScore.txt", "w"); fprintf(fp, "%d", totalScore); fclose(fp); }
	if(status == LOSE) printf("You lost the game.\n");
	if(status == WIN ) printf("You are the winner!\n");
	
	return 0;
}