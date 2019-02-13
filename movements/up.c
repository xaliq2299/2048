#include <stdio.h>
#include "up.h"

int up0000(int *grid, int i, int *totalScore, int *score){
	*score+=0; return 0;
}

int up0001(int *grid, int i, int *totalScore, int *score){
	grid[i] = grid[i+12];
	grid[i+12] = 0;
	*score+=0;
	return 1;
}

int up0010(int *grid, int i, int *totalScore, int *score){
	grid[i] = grid[i+8];
	grid[i+8] = 0;
	*score+=0;
	return 1;
}

int up0100(int *grid, int i, int *totalScore, int *score){
	grid[i] = grid[i+4];
	grid[i+4] = 0;
	*score+=0;
	return 1;
}

int up1000(int *grid, int i, int *totalScore, int *score){
	*score+=0; return 0;
}

int up0011(int *grid, int i, int *totalScore, int *score){
	if (grid[i+8] == grid[i+12]){
		grid[i] = grid[i+8]+grid[i+12];
		grid[i+4] = grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i];
		*score+=grid[i];
	}
	else{
		grid[i] = grid[i+8];
		grid[i+4] = grid[i+12];
		grid[i+8] = grid[i+12] = 0;
		*score+=0;
	}
	return 1;
}
	
int up0101(int *grid, int i, int *totalScore, int *score){
	if(grid[i+4] == grid[i+12]){
		grid[i] = grid[i+4]+grid[i+12];
		grid[i+4] = grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i];
		*score+=grid[i];
	}
	else{
		grid[i] = grid[i+4];
		grid[i+4] = grid[i+12];
		grid[i+8] = grid[i+12] = 0;
		*score+=0;
	}
	return 1;
}

int up0110(int *grid, int i, int *totalScore, int *score){
	if(grid[i+4] == grid[i+8]){
		grid[i] = grid[i+4]+grid[i+8];
		grid[i+4] = grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i];
		*score+=grid[i];
	}
	else{
		grid[i] = grid[i+4];
		grid[i+4] = grid[i+8];
		grid[i+8] = grid[i+12] = 0;
		*score+=0;
	}
	return 1;
}

int up1001(int *grid, int i, int *totalScore, int *score){
	if(grid[i] == grid[i+12]){
		grid[i] += grid[i+12];
		grid[i+4] = grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i];
		*score+=grid[i];
	}
	else{
		grid[i+4] = grid[i+12];
		grid[i+8] = grid[i+12] = 0;
		*score+=0;
	}
	return 1;
}

int up1010(int *grid, int i, int *totalScore, int *score){
	if(grid[i] == grid[i+8]){
		grid[i] += grid[i+8];
		grid[i+4] = grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i];
		*score+=grid[i];
	}
	else{
		grid[i+4] = grid[i+8];
		grid[i+8] = grid[i+12] = 0;
		*score+=0;
	}
	return 1;
}

int up1100(int *grid, int i, int *totalScore, int *score){
	if(grid[i] == grid[i+4]){
		grid[i] += grid[i+4];
		grid[i+4] = grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i];
		*score+=grid[i];
		return 1;
	}
	else{
		*score+=0;
		return 0;
	}
}

int up0111(int *grid, int i, int *totalScore, int *score){
	if(grid[i+4] == grid[i+8]){
		grid[i] = grid[i+4]+grid[i+8];
		grid[i+4] = grid[i+12];
		grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i];
		*score+=grid[i];
	}
	else if(grid[i+8] == grid[i+12]){
		grid[i] = grid[i+4];
		grid[i+4] = grid[i+8]+grid[i+12];
		grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i+4];
		*score+=grid[i+4];
	}
	else{
		grid[i] = grid[i+4];
		grid[i+4] = grid[i+8];
		grid[i+8] = grid[i+12];
		grid[i+12] = 0;
		*score+=0;
	}
	return 1;
}

int up1011(int *grid, int i, int *totalScore, int *score){
	if(grid[i] == grid[i+8]){
		grid[i] += grid[i+8];
		grid[i+4] = grid[i+12];
		grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i];
		*score+=grid[i];
	}
	else if(grid[i+8] == grid[i+12]){
		grid[i+4] = grid[i+8]+grid[i+12];
		grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i+4];
		*score+=grid[i+4];
	}
	else{
		grid[i+4] = grid[i+8];
		grid[i+8] = grid[i+12];
		grid[i+12] = 0;
		*score+=0;
	}
	return 1;
}
	
int up1101(int *grid, int i, int *totalScore, int *score){
	if(grid[i] == grid[i+4]){
		grid[i] += grid[i+4];
		grid[i+4] = grid[i+12];
		grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i];
		*score+=grid[i];
	}
	else if(grid[i+4] == grid[i+12]){
		grid[i+4] += grid[i+12];
		grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i+4];
		*score+=grid[i+4];
	}
	else{
		grid[i+8] = grid[i+12];
		grid[i+12] = 0;
		*score+=0;
	}
	return 1;
}

int up1110(int *grid, int i, int *totalScore, int *score){
	if(grid[i] == grid[i+4]){
		grid[i] += grid[i+4];
		grid[i+4] = grid[i+8];
		grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i];
		*score+=grid[i];
		return 1;
	}
	else if(grid[i+4] == grid[i+8]){
		grid[i+4] += grid[i+8];
		grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i+4];
		*score+=grid[i+4];
		return 1;
	}
	else{
		*score+=0;
		return 0;
	}
}

int up1111(int *grid, int i, int *totalScore, int *score){
	if(grid[i] == grid[i+4] && grid[i+8] == grid[i+12]){
		grid[i] = grid[i]+grid[i+4];
		grid[i+4] = grid[i+8]+grid[i+12];
		grid[i+8] = grid[i+12] = 0;
		(*totalScore)+=grid[i];
		(*totalScore)+=grid[i+4];
		*score+=grid[i]+grid[i+4];
		return 1;
	}
	else if(grid[i] == grid[i+4]){
		grid[i] = grid[i]+grid[i+4];
		grid[i+4] = grid[i+8];
		grid[i+8] = grid[i+12];
		grid[i+12] = 0;
		(*totalScore)+=grid[i];
		*score+=grid[i];
		return 1;
	}
	else if(grid[i+4] == grid[i+8]){
		grid[i+4] += grid[i+8];
		grid[i+8] = grid[i+12];
		grid[i+12] = 0;
		(*totalScore)+=grid[i+4];
		*score+=grid[i+4];
		return 1;
	}
	else if(grid[i+8] == grid[i+12]){
		grid[i+8] += grid[i+12];
		grid[i+12] = 0;
		(*totalScore)+=grid[i+8];
		*score+=grid[i+8];
		return 1;
	}
	else{
		*score+=0;
		return 0;
	}
}