#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack) {
	pstack->topIndex = -1;	
}
int SIsEmpty(Stack* pstack) {
	if(pstack->topIndex == -1) return TRUE;
	else return FALSE;
}
int SIsFull(Stack* pstack){
	if(pstack->topIndex >= STACK_LEN - 1) return TRUE;
	else return FALSE;
}

void SPush(Stack* pstack, Data data) {
	if(SIsFull(pstack)) {
		printf("Stack Overflow!\n");
		exit(-1);
	}
	
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
	
}
Data SPop(Stack* pstack) {
	int rIdx;
	if(SIsEmpty(pstack)){
		printf("Stack Empty!\n");
		exit(-1);
	}	
	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;
	
	return pstack->stackArr[rIdx];
}

Data SPeek(Stack* pstack){
	if(SIsEmpty(pstack)) {
		printf("Stack Empty!\n");
		exit(-1);
	}
	
	return pstack->stackArr[pstack->topIndex];
}
