#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isIncluded(int *arr, int n){
	int i;
	for (i = 0; i <3 ; i++) {
		if (arr[i] == n) {
			return 1;
		}
	}
	return 0;
}

int main(void) {
	
	int comInput[3] = {-1, -1, -1};
	int i, rst;
	int cnt = 10;
	srand(time(NULL));
	
	while (isIncluded(&comInput, -1)) {
		rst = rand() % 10;
		if(!isIncluded(&comInput, rst)) {
			comInput[i] = rst;
			i++;
		}
	}
	
	int strike, ball;
	int input[3];
	printf("선언할 숫자(0 0 0)\n");
	while(cnt > 0) {
		if(strike == 3) break;
		strike = 0, ball = 0;
		input[0] = -1, input[1] = -1, input[2] = -1;
		printf("> ");
		scanf("%d %d %d", &input[0], &input[1], &input[2]); 
		
		if(comInput[0] == input[0]) strike++;
		else if(isIncluded(&comInput, input[0])) ball++;
		
		if(comInput[1] == input[1]) strike++;
		else if(isIncluded(&comInput, input[1])) ball++;
		
		if(comInput[2] == input[2]) strike++;
		else if(isIncluded(&comInput, input[2])) ball++;
		
		cnt--;
		
		printf("%d strike %d ball %d left\n",strike, ball, cnt);			
	}
	
	printf("COM : %d %d %d\n",comInput[0],comInput[1],comInput[2]);
		
	printf("3 STRIKE %d count used!\n", 10 - cnt);
	
	return 0;
}
