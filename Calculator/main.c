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
	printf("%s = %d\n", exp3, Calculate(exp3)); // ������� ����. 
	
	return 0;
}

/*

((1-2)+3)*(5-2)
12-3+52-*

12-3+52-*
1
2
- -1
3
+ 2 (52-�� ����Ҷ� ���� �Ʒ� ��� ����.)
5
2
- 3
* 6 (�Ʒ� ����ִ� 2,3�� *��)

*/
