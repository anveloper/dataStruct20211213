#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int Calculate(char exp[]) {
	Stack stack;
	StackInit(&stack);
	
	int expLen = strlen(exp); 
	
	int i;
	char tok, op1, op2;
	
	for( i = 0 ; i < expLen ; i++ ) {
		tok = exp[i];
		
		if(isdigit(tok)) {
			SPush(&stack, tok - '0'); // 정수화됨. int화 
		} else {
			op2 = SPop(&stack); // 두번째 값 추출 
			op1 = SPop(&stack); // 첫번째 값 추출 
			// 무조건 연산자 전에 두개의 숫자가 존재한다. 
			switch(tok) { // 연산자로 뽑힌 tok을 만나면, 두개의 숫자를 받아서 계산한다. 
				case '+': // 값을 연산하고(첫번째, 두번째 위치 중요) 다시 스택에 넣는다. 
					SPush(&stack, op1 + op2);
					break;
				case '-':
					SPush(&stack, op1 - op2);
					break;	
				case '*':
					SPush(&stack, op1 * op2);
					break;	
				case '/':
					SPush(&stack, op1 / op2);
					break;
			} 
		}
	}
	
	return  SPop(&stack);
}
