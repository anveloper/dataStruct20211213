#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "InfixToPostfix.h"

int main(void) {
	char exp1[] = "((4+2)/4)";
	
	ConvToPostfix(exp1);
	
	printf("%s\n",exp1);
	
	return 0;
}
