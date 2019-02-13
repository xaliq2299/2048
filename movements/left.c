#include <stdio.h>
#include "left.h"

int left0000(int *grid, int i, int *totalScore, int *score){
	*score+=0;
	return 0;
}

int left0001(int *grid, int i, int *totalScore, int *score){
	grid[i*4] = grid[3+i*4];
	grid[3+i*4] = 0;
	*score+=0;
	return 1;
}

int left0010(int *grid, int i, int *totalScore, int *score){
	*score+=0;
	grid[i*4] = grid[2+i*4];
	grid[2+i*4] = 0;
	return 1;
}

int left0100(int *grid, int i, int *totalScore, int *score){
	*score+=0;
	grid[i*4] = grid[1+i*4];
	grid[1+i*4] = 0;
	return 1;
}

int left1000(int *grid, int i, int *totalScore, int *score){
	*score+=0; return 0;
}

int left0011(int *grid, int i, int *totalScore, int *score){
	if (grid[2+i*4] == grid[3+i*4]){
		grid[i*4] += grid[2+i*4];
		grid[2+i*4] = grid[3+i*4] = grid[1+i*4] = 0;
		(*totalScore)+=grid[i*4];
		*score+=grid[i*4];
	}
	else{
		grid[i*4] = grid[2+i*4];
		grid[1+i*4] = grid[3+i*4];
		grid[2+i*4] = grid[3+i*4] = 0;
		*score+=0;
	}
	return 1;
}

int left0101(int *grid, int i, int *totalScore, int *score){
	if(grid[3+i*4] == grid[1+i*4]){
		grid[i*4] += grid[1+i*4];
		grid[2+i*4] = grid[1+i*4] = grid[3+i*4] = 0;
		(*totalScore)+=grid[i*4];
		*score+=grid[i*4];
	}
	else{
		grid[i*4] = grid[1+i*4];
		grid[1+i*4] = grid[3+i*4];
		grid[2+i*4] = grid[3+i*4] = 0;
		*score+=0;
	}
	return 1;
}

int left0110(int *grid, int i, int *totalScore, int *score){
	if(grid[1+i*4] == grid[2+i*4]){
		grid[i*4] = grid[2+i*4]+grid[1+i*4];
		grid[2+i*4] = grid[1+i*4] = grid[3+i*4] = 0;
		(*totalScore)+=grid[i*4];
		*score+=grid[i*4];
	}
	else{
		grid[i*4] = grid[1+i*4];
		grid[1+i*4] = grid[2+i*4];
		grid[2+i*4] = grid[3+i*4] = 0;
		*score+=0;
	}
	return 1;
}

int left1001(int *grid, int i, int *totalScore, int *score){
	if(grid[i*4] == grid[3+i*4]){
		grid[i*4] += grid[i*4];
		grid[1+i*4] = grid[2+i*4] = grid[3+i*4] = 0;
		(*totalScore)+=grid[i*4];
		*score+=grid[i*4];
	}
	else{
		grid[1+i*4] = grid[3+i*4];
		grid[2+i*4] = grid[3+i*4] = 0;
		*score+=0;
	}
	return 1;
}

int left1010(int *grid, int i, int *totalScore, int *score){
	if(grid[i*4] == grid[2+i*4]){
		grid[i*4] += grid[2+i*4];
		grid[2+i*4] = grid[1+i*4] = grid[3+i*4] = 0;
		(*totalScore)+=grid[i*4];
		*score+=grid[i*4];
	}
	else{
		grid[1+i*4] = grid[2+i*4];
		grid[2+i*4] = grid[3+i*4] = 0;
		*score+=0;
	}
	return 1;
}

int left1100(int *grid, int i, int *totalScore, int *score){
	if(grid[i*4] == grid[1+i*4]){
		grid[i*4] += grid[1+i*4];
		grid[1+i*4] = grid[2+i*4] = grid[3+i*4] = 0;
		(*totalScore)+=grid[i*4];
		*score+=grid[i*4];
		return 1;
	}
	else{
		*score+=0;
		return 0;
	}
}

int left0111(int *grid, int i, int *totalScore, int *score){
	if(grid[1+i*4] == grid[2+i*4]){
		grid[i*4] = grid[1+i*4] + grid[2+i*4];
		grid[1+i*4] = grid[3+i*4];
		grid[2+i*4] = grid[3+i*4] = 0;
		(*totalScore)+=grid[i*4];
		*score+=grid[i*4];
	}
	else if(grid[2+i*4] == grid[3+i*4]){
		grid[i*4] = grid[1+i*4];
		grid[1+i*4] = grid[2+i*4] + grid[3+i*4];
		grid[2+i*4] = grid[3+i*4] = 0;
		(*totalScore)+=grid[1+i*4];
		*score+=grid[1+i*4];
	}
	else{
		grid[i*4] = grid[1+i*4];
		grid[1+i*4] = grid[2+i*4];
		grid[2+i*4] = grid[3+i*4];
		grid[3+i*4] = 0;
		*score+=0;
	}
	return 1;
}

int left1011(int *grid, int i, int *totalScore, int *score){
	if(grid[i*4] == grid[2+i*4]){
		grid[i*4] += grid[2+i*4];
		grid[1+i*4] = grid[3+i*4];
		grid[2+i*4] = grid[3+i*4] = 0;
		(*totalScore)+=grid[i*4];
		*score+=grid[i*4];
	}
	else if(grid[2+i*4] == grid[3+i*4]){
		grid[1+i*4] = grid[2+i*4]+grid[3+i*4];
		grid[2+i*4] = grid[3+i*4] = 0;
		(*totalScore)+=grid[1+i*4];
		*score+=grid[1+i*4];
	}
	else{
		grid[1+i*4] = grid[2+i*4];
		grid[2+i*4] = grid[3+i*4];
		grid[3+i*4] = 0;
		*score+=0;
	}
	return 1;
}

int left1101(int *grid, int i, int *totalScore, int *score){
	if(grid[i*4] == grid[1+i*4]){
		grid[i*4] += grid[1+i*4];
		grid[1+i*4] = grid[3+i*4];
		grid[2+i*4] = grid[3+i*4] = 0;
		(*totalScore)+=grid[i*4];
		*score+=grid[i*4];
	}
	else if(grid[1+i*4] == grid[3+i*4]){
		grid[1+i*4] += grid[1+i*4];
		grid[2+i*4] = grid[3+i*4] = 0;
		(*totalScore)+=grid[1+i*4];
		*score+=grid[1+i*4];
	}
	else{
		grid[2+i*4] = grid[3+i*4];
		grid[3+i*4] = 0;
		*score+=0;
	}
	return 1;
}

int left1110(int *grid, int i, int *totalScore, int *score){
	if(grid[i*4] == grid[1+i*4]){
		grid[i*4] += grid[1+i*4];
		grid[1+i*4] = grid[2+i*4];
		grid[2+i*4] = grid[3+i*4] = 0;
		(*totalScore)+=grid[i*4];
		*score+=grid[i*4];
		return 1;
	}
	else if(grid[1+i*4] == grid[2+i*4]){
		grid[1+i*4] += grid[2+i*4];
		grid[2+i*4] = grid[3+i*4] = 0;
		(*totalScore)+=grid[1+i*4];
		*score+=grid[1+i*4];
		return 1;
	}
	else{
		*score+=0;
		return 0;
	}
}

int left1111(int *grid, int i, int *totalScore, int *score){
	if(grid[i*4] == grid[1+i*4] && grid[2+i*4] == grid[3+i*4]){
		grid[i*4] += grid[1+i*4];
		grid[1+i*4] = grid[2+i*4]+grid[3+i*4];
		grid[2+i*4] = grid[3+i*4] = 0;
		(*totalScore)+=grid[i*4];
		(*totalScore)+=grid[1+i*4];
		*score+=grid[i*4]+grid[1+i*4];
		return 1;
	}
	else if(grid[i*4] == grid[1+i*4]){
		grid[i*4] += grid[1+i*4];
		grid[1+i*4] = grid[2+i*4];
		grid[2+i*4] = grid[3+i*4];
		grid[3+i*4] = 0;
		(*totalScore)+=grid[i*4];
		*score+=grid[i*4];
		return 1;
	}
	else if(grid[1+i*4] == grid[2+i*4]){
		grid[1+i*4] += grid[2+i*4];
		grid[2+i*4] = grid[3+i*4];
		grid[3+i*4] = 0;
		(*totalScore)+=grid[1+i*4];
		*score+=grid[1+i*4];
		return 1;
	}
	else if(grid[2+i*4] == grid[3+i*4]){
		grid[2+i*4] += grid[3+i*4];
		grid[3+i*4] = 0;
		(*totalScore)+=grid[2+i*4];
		*score+=grid[2+i*4];
		return 1;
	}		
	else{
		*score+=0;
		return 0;
	}
}
