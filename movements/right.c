#include <stdio.h>
#include "right.h"

int right0000(int *grid, int i, int *totalScore, int *score){
	*score+=0; return 0;
}

int right0001(int *grid, int i, int *totalScore, int *score){
	*score+=0; return 0;
}

int right0010(int *grid, int i, int *totalScore, int *score){
	grid[3+i*4] = grid[2+i*4];
	grid[2+i*4] = 0;
	*score+=0;
	return 1;
}

int right0100(int *grid, int i, int *totalScore, int *score){
	grid[3+i*4] = grid[1+i*4];
	grid[1+i*4] = 0;
	*score+=0;
	return 1;
}

int right1000(int *grid, int i, int *totalScore, int *score){
	grid[3+i*4] = grid[0+i*4];
	grid[0+i*4] = 0;
	*score+=0;
	return 1;
}

int right0011(int *grid, int i, int *totalScore, int *score){
	if (grid[2+i*4] == grid[3+i*4]){
		grid[3+i*4] += grid[2+i*4];
		grid[0+i*4] = grid[1+i*4] = grid[2+i*4] = 0;
		(*totalScore)+=grid[3+i*4];
		*score+=grid[3+i*4];
		return 1;
	}
	else{
		*score+=0;
		return 0;
	}
}

int right0101(int *grid, int i, int *totalScore, int *score){
	if(grid[3+i*4] == grid[1+i*4]){
		grid[3+i*4] += grid[1+i*4];
		grid[2+i*4] = grid[1+i*4] = grid[i*4] = 0;
		(*totalScore)+=grid[3+i*4];
		*score+=grid[3+i*4];
	}
	else{
		grid[2+i*4] = grid[1+i*4];
		grid[1+i*4] = grid[i*4] = 0;
		*score+=0;
	}
	return 1;
}

int right0110(int *grid, int i, int *totalScore, int *score){
	if(grid[1+i*4] == grid[2+i*4]){
		grid[3+i*4] = grid[2+i*4]+grid[1+i*4];
		grid[2+i*4] = grid[1+i*4] = grid[i*4] = 0;
		(*totalScore)+=grid[3+i*4];
		*score+=grid[3+i*4];
	}
	else{
		grid[3+i*4] = grid[2+i*4];
		grid[2+i*4] = grid[1+i*4];
		grid[1+i*4] = grid[i*4] = 0;
		*score+=0;
	}
	return 1;
}

int right1001(int *grid, int i, int *totalScore, int *score){
	if(grid[i*4] == grid[3+i*4]){
		grid[3+i*4] += grid[i*4];
		grid[1+i*4] = grid[2+i*4] = grid[i*4] = 0;
		(*totalScore)+=grid[3+i*4];
		*score+=grid[3+i*4];
	}
	else{
		grid[2+i*4] = grid[i*4];
		grid[i*4] = grid[1+i*4] = 0;
		*score+=0;
	}
	return 1;
}

int right1010(int *grid, int i, int *totalScore, int *score){
	if(grid[i*4] == grid[2+i*4]){
		grid[3+i*4] = grid[2+i*4]+grid[i*4];
		grid[2+i*4] = grid[1+i*4] = grid[i*4] = 0;
		(*totalScore)+=grid[3+i*4];
		*score+=grid[3+i*4];
	}
	else{
		grid[3+i*4] = grid[2+i*4];
		grid[2+i*4] = grid[i*4];
		grid[1+i*4] = grid[i*4] = 0;
		*score+=0;
	}
	return 1;
}

int right1100(int *grid, int i, int *totalScore, int *score){
	if(grid[i*4] == grid[1+i*4]){
		grid[3+i*4] = grid[1+i*4]+grid[i*4];
		grid[1+i*4] = grid[2+i*4] = grid[i*4] = 0;
		(*totalScore)+=grid[3+i*4];
		*score+=grid[3+i*4];
	}
	else{
		grid[3+i*4] = grid[1+i*4];
		grid[2+i*4] = grid[i*4];
		grid[1+i*4] = grid[i*4] = 0;
		*score+=0;
	}
	return 1;
}

int right0111(int *grid, int i, int *totalScore, int *score){
	if(grid[2+i*4] == grid[3+i*4]){
		grid[3+i*4] += grid[2+i*4];
		grid[2+i*4] = grid[1+i*4];
		grid[1+i*4] = grid[i*4] = 0;
		(*totalScore)+=grid[3+i*4];
		*score+=grid[3+i*4];
		return 1;
	}
	else if(grid[1+i*4] == grid[2+i*4]){ //problem !!!
		grid[2+i*4] += grid[2+i*4];
		grid[i*4] = grid[1+i*4] = 0;
		(*totalScore)+=grid[2+i*4];
		*score+=grid[2+i*4];
		return 1;
	}
	else{
		*score+=0;
		return 0;
	}
}

int right1011(int *grid, int i, int *totalScore, int *score){
	if(grid[2+i*4] == grid[3+i*4]){
		grid[3+i*4] += grid[2+i*4];
		grid[2+i*4] = grid[i*4];
		grid[1+i*4] = grid[i*4] = 0;
		(*totalScore)+=grid[3+i*4];
		*score+=grid[3+i*4];
	}
	else if(grid[i*4] == grid[2+i*4]){
		grid[2+i*4] += grid[i*4];
		grid[1+i*4] = grid[i*4] = 0;
		(*totalScore)+=grid[2+i*4];
		*score+=grid[2+i*4];
	}
	else{
		grid[i*4+1] = grid[i*4];
		grid[i*4] = 0;
		*score+=0;
	}
	return 1;
}

int right1101(int *grid, int i, int *totalScore, int *score){
	if(grid[1+i*4] == grid[3+i*4]){
		grid[3+i*4] += grid[1+i*4];
		grid[2+i*4] = grid[i*4];
		grid[1+i*4] = grid[i*4] = 0;
		(*totalScore)+=grid[3+i*4];
		*score+=grid[3+i*4];
	}
	else if(grid[i*4] == grid[1+i*4]){
		grid[2+i*4] = grid[1+i*4]+grid[i*4];
		grid[1+i*4] = grid[i*4] = 0;
		(*totalScore)+=grid[2+i*4];
		*score+=grid[2+i*4];
	}
	else{
		grid[2+i*4] = grid[1+i*4];
		grid[1+i*4] = grid[i*4];
		grid[i*4] = 0;
		*score+=0;
	}
	return 1;
}

int right1110(int *grid, int i, int *totalScore, int *score){
	if(grid[1+i*4] == grid[2+i*4]){
		grid[3+i*4] = grid[1+i*4]+grid[2+i*4];
		grid[2+i*4] = grid[0+i*4];
		grid[1+i*4] = grid[0+i*4] = 0;
		(*totalScore)+=grid[3+i*4];
		*score+=grid[3+i*4];
	}
	else if(grid[1+i*4] == grid[0+4*i]){
		grid[3+i*4] = grid[2+i*4];
		grid[2+i*4] = grid[1+i*4]+grid[0+i*4];
		grid[0+i*4] = grid[1+i*4] = 0;
		(*totalScore)+=grid[2+i*4];
		*score+=grid[2+i*4];
	}
	else{
		grid[3+i*4] = grid[2+i*4];
		grid[2+i*4] = grid[1+i*4];
		grid[1+i*4] = grid[0+i*4];
		grid[0+i*4] = 0;
		*score+=0;
	}
	return 1;
}

int right1111(int *grid, int i, int *totalScore, int *score){
	if(grid[2+i*4] == grid[3+i*4] && grid[i*4+0] == grid[1+i*4]){
		grid[3+i*4] += grid[2+i*4];
		grid[2+i*4] = grid[1+i*4]+grid[i*4];
		grid[i*4] = grid[1+i*4] = 0;
		(*totalScore)+=grid[3+i*4];
		(*totalScore)+=grid[2+i*4];
		*score+=grid[3+i*4]+grid[2+i*4];
		return 1;
	}
	else if(grid[3+i*4] == grid[2+i*4]){
		grid[3+i*4] += grid[2+i*4];
		grid[2+i*4] = grid[1+i*4];
		grid[1+i*4] = grid[0+i*4];
		grid[0+i*4] = 0;
		(*totalScore)+=grid[3+i*4];
		*score+=grid[3+i*4];
		return 1;
	}
	else if(grid[2+i*4] == grid[1+i*4]){
		grid[2+i*4] += grid[1+i*4];
		grid[1+i*4] = grid[0+i*4];
		grid[0+i*4] = 0;
		(*totalScore)+=grid[2+i*4];
		*score+=grid[2+i*4];
		return 1;
	}
	else if(grid[0+i*4] == grid[1+i*4]){
		grid[1+i*4] += grid[0+i*4];
		grid[0+i*4] = 0;
		(*totalScore)+=grid[1+i*4];
		*score+=grid[1+i*4];
		return 1;
	}
	else{
		*score+=0;
		return 0;
	}
}
