#include <stdio.h>
#include "movements.h"
#include "up.h"
#include "down.h"
#include "right.h"
#include "left.h"

int up(int *grid, int *totalScore, int *score){
	int change = 0;
	
	for(int i=0;i<4;i++){
		//case 0 0 0 0
		if(grid[i] == 0 && grid[i+4] == 0 && grid[i+8] == 0 && grid[i+12] == 0)
			change+=up0000(grid, i, totalScore, score);
		//case 0 0 0 1
		else if(grid[i] == 0 && grid[i+4] == 0 && grid[i+8] == 0 && grid[i+12] != 0)
			change+=up0001(grid, i, totalScore, score);
		//case 0 0 1 0
		else if(grid[i] == 0 && grid[i+4] == 0 && grid[i+8] != 0 && grid[i+12] == 0)
			change+=up0010(grid, i, totalScore, score);
		//case 0 1 0 0 
		else if(grid[i] == 0 && grid[i+4] != 0 && grid[i+8] == 0 && grid[i+12] == 0)
			change+=up0100(grid, i, totalScore, score);
		//case 1 0 0 0
		else if(grid[i] != 0 && grid[i+4] == 0 && grid[i+8] == 0 && grid[i+12] == 0)
			change+=up1000(grid, i, totalScore, score);
		//case 0 0 1 1 
		else if(grid[i] == 0 && grid[i+4] == 0 && grid[i+8] != 0 && grid[i+12] != 0)
			change+=up0011(grid, i, totalScore, score);
		//case 0 1 0 1
		else if(grid[i] == 0 && grid[i+4] != 0 && grid[i+8] == 0 && grid[i+12] != 0)
			change+=up0101(grid, i, totalScore, score);
		//case 0 1 1 0
		else if(grid[i] == 0 && grid[i+4] != 0 && grid[i+8] != 0 && grid[i+12] == 0)
			change+=up0110(grid, i, totalScore, score);
		//case 1 0 0 1
		else if(grid[i] != 0 && grid[i+4] == 0 && grid[i+8] == 0 && grid[i+12] != 0)
			change+=up1001(grid, i, totalScore, score);
		//case 1 0 1 0 
		else if(grid[i] != 0 && grid[i+4] == 0 && grid[i+8] != 0 && grid[i+12] == 0)
			change+=up1010(grid, i, totalScore, score);
		//case 1 1 0 0 
		else if(grid[i] != 0 && grid[i+4] != 0 && grid[i+8] == 0 && grid[i+12] == 0)
			change+=up1100(grid, i, totalScore, score);
		//case 0 1 1 1 
		else if(grid[i] == 0 && grid[i+4] != 0 && grid[i+8] != 0 && grid[i+12] != 0)
			change+=up0111(grid, i, totalScore, score);
		//case 1 0 1 1
		else if(grid[i] != 0 && grid[i+4] == 0 && grid[i+8] != 0 && grid[i+12] != 0)
			change+=up1011(grid, i, totalScore, score);
		//case 1 1 0 1
		else if(grid[i] != 0 && grid[i+4] != 0 && grid[i+8] == 0 && grid[i+12] != 0)
			change+=up1101(grid, i, totalScore, score);
		//case 1 1 1 0
		else if(grid[i] != 0 && grid[i+4] != 0 && grid[i+8] != 0 && grid[i+12] == 0)
			change+=up1110(grid, i, totalScore, score);
		//case 1 1 1 1 
		else if(grid[i] != 0 && grid[i+4] != 0 && grid[i+8] != 0 && grid[i+12] != 0)
			change+=up1111(grid, i, totalScore, score);
	}
	return change;
}

int down(int *grid, int *totalScore, int *score){
	int change = 0;
	
	for(int i=0;i<4;i++){
		//case 0 0 0 0
		if(grid[i] == 0 && grid[i+4] == 0 && grid[i+8] == 0 && grid[i+12] == 0)
			change+=down0000(grid, i, totalScore, score);
		//case 0 0 0 1
		else if(grid[i] == 0 && grid[i+4] == 0 && grid[i+8] == 0 && grid[i+12] != 0)
			change+=down0001(grid, i, totalScore, score);
		//case 0 0 1 0
		else if(grid[i] == 0 && grid[i+4] == 0 && grid[i+8] != 0 && grid[i+12] == 0)
			change+=down0010(grid, i, totalScore, score);
		//case 0 1 0 0 
		else if(grid[i] == 0 && grid[i+4] != 0 && grid[i+8] == 0 && grid[i+12] == 0)
			change+=down0100(grid, i, totalScore, score);
		//case 1 0 0 0
		else if(grid[i] != 0 && grid[i+4] == 0 && grid[i+8] == 0 && grid[i+12] == 0)
			change+=down1000(grid, i, totalScore, score);
		//case 0 0 1 1 
		else if(grid[i] == 0 && grid[i+4] == 0 && grid[i+8] != 0 && grid[i+12] != 0)
			change+=down0011(grid, i, totalScore, score);
		//case 0 1 0 1
		else if(grid[i] == 0 && grid[i+4] != 0 && grid[i+8] == 0 && grid[i+12] != 0)
			change+=down0101(grid, i, totalScore, score);
		//case 0 1 1 0
		else if(grid[i] == 0 && grid[i+4] != 0 && grid[i+8] != 0 && grid[i+12] == 0)
			change+=down0110(grid, i, totalScore, score);
		//case 1 0 0 1
		else if(grid[i] != 0 && grid[i+4] == 0 && grid[i+8] == 0 && grid[i+12] != 0)
			change+=down1001(grid, i, totalScore, score);
		//case 1 0 1 0 
		else if(grid[i] != 0 && grid[i+4] == 0 && grid[i+8] != 0 && grid[i+12] == 0)
			change+=down1010(grid, i, totalScore, score);
		//case 1 1 0 0 
		else if(grid[i] != 0 && grid[i+4] != 0 && grid[i+8] == 0 && grid[i+12] == 0)
			change+=down1100(grid, i, totalScore, score);
		//case 0 1 1 1
		else if(grid[i] == 0 && grid[i+4] != 0 && grid[i+8] != 0 && grid[i+12] != 0)
			change+=down0111(grid, i, totalScore, score);
		//case 1 0 1 1
		else if(grid[i] != 0 && grid[i+4] == 0 && grid[i+8] != 0 && grid[i+12] != 0)
			change+=down1011(grid, i, totalScore, score);
		//case 1 1 0 1
		else if(grid[i] != 0 && grid[i+4] != 0 && grid[i+8] == 0 && grid[i+12] != 0)
			change+=down1101(grid, i, totalScore, score);
		//case 1 1 1 0
		else if(grid[i] != 0 && grid[i+4] != 0 && grid[i+8] != 0 && grid[i+12] == 0)
			change+=down1110(grid, i, totalScore, score);
		//case 1 1 1 1 
		else if(grid[i] != 0 && grid[i+4] != 0 && grid[i+8] != 0 && grid[i+12] != 0)
			change+=down1111(grid, i, totalScore, score);
	}
	return change;
}

int right(int *grid, int *totalScore, int *score){
	int change = 0;
	
	for(int i=0;i<4;i++){
		//case 0 0 0 0
		if(grid[0+i*4] == 0 && grid[1+i*4] == 0 && grid[2+i*4] == 0 && grid[3+i*4] == 0)
			change+=right0000(grid, i, totalScore, score);
		//case 0 0 0 1
		else if(grid[0+i*4] == 0 && grid[1+i*4] == 0 && grid[2+i*4] == 0 && grid[3+i*4] != 0)
			change+=right0001(grid, i, totalScore, score);
		//case 0 0 1 0
		else if(grid[0+i*4] == 0 && grid[1+i*4] == 0 && grid[2+i*4] != 0 && grid[3+i*4] == 0)
			change+=right0010(grid, i, totalScore, score);
		//case 0 1 0 0 
		else if(grid[0+i*4] == 0 && grid[1+i*4] != 0 && grid[2+i*4] == 0 && grid[3+i*4] == 0)
			change+=right0100(grid, i, totalScore, score);
		//case 1 0 0 0
		else if(grid[0+i*4] != 0 && grid[1+i*4] == 0 && grid[2+i*4] == 0 && grid[3+i*4] == 0)
			change+=right1000(grid, i, totalScore, score);
		//case 0 0 1 1 
		else if(grid[0+i*4] == 0 && grid[1+i*4] == 0 && grid[2+i*4] != 0 && grid[3+i*4] != 0)
			change+=right0011(grid, i, totalScore, score);
		//case 0 1 0 1
		else if(grid[0+i*4] == 0 && grid[1+i*4] != 0 && grid[2+i*4] == 0 && grid[3+i*4] != 0)
			change+=right0101(grid, i, totalScore, score);
		//case 0 1 1 0
		else if(grid[0+i*4] == 0 && grid[1+i*4] != 0 && grid[2+i*4] != 0 && grid[3+i*4] == 0)
			change+=right0110(grid, i, totalScore, score);
		//case 1 0 0 1
		else if(grid[0+i*4] != 0 && grid[1+i*4] == 0 && grid[2+i*4] == 0 && grid[3+i*4] != 0)
			change+=right1001(grid, i, totalScore, score);
		//case 1 0 1 0 
		else if(grid[0+i*4] != 0 && grid[1+i*4] == 0 && grid[2+i*4] != 0 && grid[3+i*4] == 0)
			change+=right1010(grid, i, totalScore, score);
		//case 1 1 0 0 
		else if(grid[0+i*4] != 0 && grid[1+i*4] != 0 && grid[2+i*4] == 0 && grid[3+i*4] == 0)
			change+=right1100(grid, i, totalScore, score);
		//case 0 1 1 1
		else if(grid[i*4] == 0 && grid[1+i*4] != 0 && grid[2+i*4] != 0 && grid[3+i*4] != 0)
			change+=right0111(grid, i, totalScore, score);
		//case 1 0 1 1
		else if(grid[i*4] != 0 && grid[1+i*4] == 0 && grid[2+i*4] != 0 && grid[3+i*4] != 0)
			change+=right1011(grid, i, totalScore, score);
		//case 1 1 0 1
		else if(grid[0+i*4] != 0 && grid[1+i*4] != 0 && grid[2+i*4] == 0 && grid[3+i*4] != 0)
			change+=right1101(grid, i, totalScore, score);
		//case 1 1 1 0
		if(grid[0+i*4] != 0 && grid[1+i*4] != 0 && grid[2+i*4] != 0 && grid[3+i*4] == 0)
			change+=right1110(grid, i, totalScore, score);
		//case 1 1 1 1
		else if(grid[0+i*4] != 0 && grid[1+i*4] != 0 && grid[2+i*4] != 0 && grid[3+i*4] != 0)
			change+=right1111(grid, i, totalScore, score);
	}	
	return change;
}

int left(int *grid, int *totalScore, int *score){
	int change = 0;
	
	for(int i=0;i<4;i++){
		//case 0 0 0 0
		if(grid[0+i*4] == 0 && grid[1+i*4] == 0 && grid[2+i*4] == 0 && grid[3+i*4] == 0)
			change+=left0000(grid, i, totalScore, score);
		//case 0 0 0 1
		else if(grid[0+i*4] == 0 && grid[1+i*4] == 0 && grid[2+i*4] == 0 && grid[3+i*4] != 0)
			change+=left0001(grid, i, totalScore, score);
		//case 0 0 1 0
		else if(grid[0+i*4] == 0 && grid[1+i*4] == 0 && grid[2+i*4] != 0 && grid[3+i*4] == 0)
			change+=left0010(grid, i, totalScore, score);
		//case 0 1 0 0 
		else if(grid[0+i*4] == 0 && grid[1+i*4] != 0 && grid[2+i*4] == 0 && grid[3+i*4] == 0)
			change+=left0100(grid, i, totalScore, score);
		//case 1 0 0 0
		else if(grid[0+i*4] != 0 && grid[1+i*4] == 0 && grid[2+i*4] == 0 && grid[3+i*4] == 0)
			change+=left1000(grid, i, totalScore, score);
		//case 0 0 1 1 
		else if(grid[0+i*4] == 0 && grid[1+i*4] == 0 && grid[2+i*4] != 0 && grid[3+i*4] != 0)
			change+=left0011(grid, i, totalScore, score);
		//case 0 1 0 1
		else if(grid[0+i*4] == 0 && grid[1+i*4] != 0 && grid[2+i*4] == 0 && grid[3+i*4] != 0)	
			change+=left0101(grid, i, totalScore, score);
		//case 0 1 1 0
		else if(grid[0+i*4] == 0 && grid[1+i*4] != 0 && grid[2+i*4] != 0 && grid[3+i*4] == 0)
			change+=left0110(grid, i, totalScore, score);
		//case 1 0 0 1
		else if(grid[0+i*4] != 0 && grid[1+i*4] == 0 && grid[2+i*4] == 0 && grid[3+i*4] != 0)	
			change+=left1001(grid, i, totalScore, score);
		//case 1 0 1 0
		else if(grid[0+i*4] != 0 && grid[1+i*4] == 0 && grid[2+i*4] != 0 && grid[3+i*4] == 0)
			change+=left1010(grid, i, totalScore, score);
		//case 1 1 0 0
		else if(grid[0+i*4] != 0 && grid[1+i*4] != 0 && grid[2+i*4] == 0 && grid[3+i*4] == 0)
			change+=left1100(grid, i, totalScore, score);
		//case 0 1 1 1
		else if(grid[i*4] == 0 && grid[1+i*4] != 0 && grid[2+i*4] != 0 && grid[3+i*4] != 0)	
			change+=left0111(grid, i, totalScore, score);
		//case 1 0 1 1
		else if(grid[i*4] != 0 && grid[1+i*4] == 0 && grid[2+i*4] != 0 && grid[3+i*4] != 0)
			change+=left1011(grid, i, totalScore, score);
		//case 1 1 0 1
		else if(grid[0+i*4] != 0 && grid[1+i*4] != 0 && grid[2+i*4] == 0 && grid[3+i*4] != 0)
			change+=left1101(grid, i, totalScore, score);
		//case 1 1 1 0
		else if(grid[i*4] != 0 && grid[1+i*4] != 0 && grid[2+i*4] != 0 && grid[3+i*4] == 0)
			change+=left1110(grid, i, totalScore, score);
		//case 1 1 1 1
		else if(grid[i*4] != 0 && grid[1+i*4] != 0 && grid[2+i*4] != 0 && grid[3+i*4] != 0)
			change+=left1111(grid, i, totalScore, score);
	}
	return change;
}