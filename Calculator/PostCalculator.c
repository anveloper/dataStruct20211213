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
			SPush(&stack, tok - '0'); // ����ȭ��. intȭ 
		} else {
			op2 = SPop(&stack); // �ι�° �� ���� 
			op1 = SPop(&stack); // ù��° �� ���� 
			// ������ ������ ���� �ΰ��� ���ڰ� �����Ѵ�. 
			switch(tok) { // �����ڷ� ���� tok�� ������, �ΰ��� ���ڸ� �޾Ƽ� ����Ѵ�. 
				case '+': // ���� �����ϰ�(ù��°, �ι�° ��ġ �߿�) �ٽ� ���ÿ� �ִ´�. 
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
