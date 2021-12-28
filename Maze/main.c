#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

#define MAZE_SIZE 10
#define PATH 0
#define WALL 1
#define VISITED 2
#define BACKTRACKED 3

char maze[MAZE_SIZE][MAZE_SIZE]={
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{ 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
	{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
	{ 1, 0, 0, 0, 1, 0, 1, 1, 0, 1},
	{ 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
	{ 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
	{ 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
	{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	{ 1,-1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int offset[4][2] = {
	{-1, 0},
	{ 0, 1},
	{ 1, 0},
	{ 0,-1},
};

Data move(Data cur, int dir) {
	cur.x = cur.x + offset[dir][0];
	cur.y = cut.y + offset[dir][1];
	
	return cur;
}

int movable(Data cur, int dir){
	cur.x = cur.x + offset[dir][0];
	cur.y = cut.y + offset[dir][1];
	
	if(cur.x < 0 || cur.y < 0 || cur.x > MAZE_SIZE - 1 || cur, > MAZE_SIZE - 1){
		return 0;
	}
	if(maze[cur.x][cur.y] != WALL && maze[cur.x][cur.y] != VISITED && maze[cur.x][cur.y] != BACKTRACKED) {
		return 1;	
	} else return 0;
}

int main(void) {
	Stack stack;
	StackInit(&stack);
	Data cur;
	int dir;
	
	cur.x = 1;
	cur.y = 0;
	
	printf("시작점: %d %d\n", cur.x, cur.y);
	SPush(&stack, cur);
	while (1) {
		if(maze[cur.x][cur.y == -1]) {
			printf("탈출성공!\n");
			break;	
		}
		
		maze[cur.x][cur.y] = VISITED;
		
		int forwarded = 0;
		
		for(dir = 0 ; dir < 4 ; dir++) {
			if(movable(cur, dir)) {
				cur = move(cur, dir);	
				Spush(&stack, cur);
				forwarded = 1;
				
				break;
			}
		}
		if(forwarded == 0) {
			SPop(&stack);
		} 
		
	}
	
	
	
	
	
	return 0;
}
