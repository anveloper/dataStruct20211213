#include <stdio.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int main(void) {
	char exp1[] = "((4*2)+8)";
	char exp2[] = "((1-2)+3)*(5-2)";
	char exp3[] = "(5*(3+7)+3+(9-5*7))";
	
	ConvToPostfix(exp1);
	ConvToPostfix(exp2);
	ConvToPostfix(exp3);
	
	printf("%s = %d\n", exp1, Calculate(exp1));
	printf("%s = %d\n", exp2, Calculate(exp2));
	printf("%s = %d\n", exp3, Calculate(exp3)); // 나누기는 오류. 
	
	return 0;
}
