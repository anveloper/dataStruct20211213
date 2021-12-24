#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void) {
	Stack stack;
	StackInit(&stack);
	
	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);
	SPush(&stack, 6);
	SPush(&stack, 7);
	SPush(&stack, 8);
	SPush(&stack, 9);
	SPush(&stack, 10);
	
	while(!SIsEmpty(&stack)) {
		printf("%d ", SPop(&stack));
	}
	
	int i = 0;
	for(i = 0; i< 10 ; i++){
		printf("%d ", stack.stackArr[i]);
	}
	
	return 0;
}
