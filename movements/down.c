#include <stdio.h>
#include "down.h"

int down0000(int *grid, int i, int *totalScore, int *score){
	*score+=0; return 0;
}

int down0001(int *grid, int i, int *totalScore, int *score){
	*score+=0; return 0;
}

int down0010(int *grid, int i, int *totalScore, int *score){
	*score+=0;
	grid[i+12] = grid[i+8];
	grid[i+8] = 0;
	return 1;
}

int down0100(int *grid, int i, int *totalScore, int *score){
	*score+=0;
	grid[i+12] = grid[i+4];
	grid[i+4] = 0;
	return 1;
}
	
int down1000(int *grid, int i, int *totalScore, int *score){
	*score+=0;
	grid[i+12] = grid[i];
	grid[i] = 0;
	return 1;
}

int down0011(int *grid, int i, int *totalScore, int *score){
	if (grid[i+8] == grid[i+12]){
		grid[i+12] += grid[i+8];
		grid[i+4] = grid[i+8] = grid[i] = 0;
		(*totalScore)+=grid[i+12];
		*score+=grid[i+12];
		return 1;
	}
	else{
		*score+=0;
		return 0;
	}
}

int down0101(int *grid, int i, int *totalScore, int *score){
	if(grid[i+4] == grid[i+12]){
		grid[i+12] += grid[i+4];
		grid[i+4] = grid[i+8] = grid[i] = 0;
		(*totalScore)+=grid[i+12];
		*score=grid[i+12];
	}
	else{
		grid[i+8] = grid[i+4];
		grid[i] = grid[i+4] = 0;
		*score+=0;
	}
	return 1;
}

int down0110(int *grid, int i, int *totalScore, int *score){
	if(grid[i+4] == grid[i+8]){
		grid[i+12] = grid[i+4]+grid[i+8];
		grid[i+4] = grid[i+8] = grid[i] = 0;
		(*totalScore)+=grid[i+12];
		*score+=grid[i+12];
	}
	else{
		grid[i+12] = grid[i+8];
		grid[i+8] = grid[i+4];
		grid[i+4] = grid[i] = 0;
		*score+=0;
	}
	return 1;
}

int down1001(int *grid, int i, int *totalScore, int *score){
	if(grid[i] == grid[i+12]){
		grid[i+12] += grid[i];
		grid[i+4] = grid[i+8] = grid[i] = 0;
		(*totalScore)+=grid[i+12];
		*score+=grid[i+12];
	}
	else{
		grid[i+8] = grid[i];
		grid[i+4] = grid[i] = 0;
		*score+=0;
	}
	return 1;
}
	
int down1010(int *grid, int i, int *totalScore, int *score){
	if(grid[i] == grid[i+8]){
		grid[i+12] = grid[i+8]+grid[i];
		grid[i+8] = grid[i+4] = grid[i] = 0;
		(*totalScore)+=grid[i+12];
		*score+=grid[i+12];
	}
	else{
		grid[i+12] = grid[i+8];
		grid[i+8] = grid[i];
		grid[i+4] = grid[i] = 0;
		*score+=0;
	}
	return 1;
}

int down1100(int *grid, int i, int *totalScore, int *score){
	if(grid[i] == grid[i+4]){
		grid[i+12] = grid[i+4]+grid[i];
		grid[i+4] = grid[i+8] = grid[i] = 0;
		(*totalScore)+=grid[i+12];
		*score+=grid[i+12];
	}
	else{
		grid[i+12] = grid[i+4];
		grid[i+8] = grid[i];
		grid[i+4] = grid[i] = 0;
		*score+=0;
	}
	return 1;
}

int down0111(int *grid, int i, int *totalScore, int *score){
	if(grid[i+8] == grid[i+12]){
		grid[i+12] += grid[i+8];
		grid[i+8] = grid[i+4];
		grid[i+4] = grid[i] = 0;
		(*totalScore)+=grid[i+12];
		*score+=grid[i+12];
		return 1;
	}	
	else if(grid[i+8] == grid[i+4]){
		grid[i+8] += grid[i+4];
		grid[i+4] = grid[i] = 0;
		(*totalScore)+=grid[i+8];
		*score+=grid[i+8];
		return 1;
	}	
	else{
		*score+=0;
		return 0;
	}
}
	
int down1011(int *grid, int i, int *totalScore, int *score){
	if(grid[i+8] == grid[i+12]){
		grid[i+12] += grid[i+8];
		grid[i+8] = grid[i];
		grid[i+4] = grid[i] = 0;
		(*totalScore)+=grid[i+12];
		*score+=grid[i+12];
	}
	else if(grid[i] == grid[i+8]){
		grid[i+8] += grid[i];
		grid[i+4] = grid[i] = 0;
		(*totalScore)+=grid[i+8];
		*score+=grid[i+8];
	}
	else{
		grid[i+4] = grid[i];
		grid[i] = 0;
		*score+=0;
	}
	return 1;
}

int down1101(int *grid, int i, int *totalScore, int *score){
	if(grid[i+4] == grid[i+12]){
		grid[i+12] += grid[i+4];
		grid[i+8] = grid[i];
		grid[i+4] = grid[i] = 0;
		(*totalScore)+=grid[i+12];
		*score+=grid[i+12];
	}
	else if(grid[i] == grid[i+4]){
		grid[i+8] = grid[i+4] + grid[i];
		grid[i+4] = grid[i] = 0;
		(*totalScore)+=grid[i+8];
		*score+=grid[i+8];
	}	
	else{
		grid[i+8] = grid[i+4];
		grid[i+4] = grid[i];
		grid[i] = 0;
		*score+=0;
	}	
	return 1;
}

int down1110(int *grid, int i, int *totalScore, int *score){
	if(grid[i+4] == grid[i+8]){
		grid[i+12] = grid[i+4]+grid[i+8];
		grid[i+8] = grid[i];
		grid[i+4] = grid[i] = 0;
		(*totalScore)+=grid[i+12];
		*score+=grid[i+12];
	}
	else if(grid[i+4] == grid[i]){
		grid[i+12] = grid[i+8];
		grid[i+8] = grid[i+4]+grid[i];
		grid[i] = grid[i+4] = 0;
		(*totalScore)+=grid[i+8];
		*score+=grid[i+8];
	}
	else{
		grid[i+12] = grid[i+8];
		grid[i+8] = grid[i+4];
		grid[i+4] = grid[i];
		grid[i] = 0;
		*score+=0;
	}
	return 1;
}

int down1111(int *grid, int i, int *totalScore, int *score){
	if(grid[i+8] == grid[i+12] && grid[i] == grid[i+4]){
		grid[i+12] += grid[i+8];
		grid[i+8] = grid[i+4]+grid[i];
		grid[i+4] = grid[i] = 0;
		(*totalScore)+=grid[i+12];
		(*totalScore)+=grid[i+8];
		*score+=grid[i+12]+grid[i+8];
		return 1;
	}
	else if(grid[i+12] == grid[i+8]){
		grid[i+12] += grid[i+8];
		grid[i+8] = grid[i+4];
		grid[i+4] = grid[i];
		grid[i] = 0;
		(*totalScore)+=grid[i+12];
		*score+=grid[i+12];
		return 1;
	}
	else if(grid[i+8] == grid[i+4]){
		grid[i+8] += grid[i+4];
		grid[i+4] = grid[i];
		grid[i] = 0;
		(*totalScore)+=grid[i+8];
		*score+=grid[i+8];
		return 1;
	}
	else if(grid[i] == grid[i+4]){
		grid[i+4] += grid[i];
		grid[i] = 0;
		(*totalScore)+=grid[i+4];
		*score+=grid[i+4];
		return 1;
	}
	else{
		*score+=0;
		return 0;
	}
}
