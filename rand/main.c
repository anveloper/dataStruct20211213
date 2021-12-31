#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int whoWin(int userPick, int comPick) {
	if (userPick == comPick) {
		return 0;
	} else if (userPick == comPick + 1 || userPick == comPick - 2) {
		return 1;
	} else {
		return -1;
	}
}

int main(void) {
	printf("난수의 범위 : 0부터 %d\n", RAND_MAX);

	srand(time(NULL));
	
	printf("==주사위 확률이 같을까?==\n");
	int i, rst;
	int numArr[5] = {0, 0, 0, 0, 0};
	
	for (i = 0 ; i < 100000 ; i++) {
		rst = rand() % 5;
		numArr[rst] = numArr[rst] + 1;
	}	 
	printf("1 : %d, 2 : %d, 3 : %d, 4 : %d, 5 : %d\n", numArr[0], numArr[1], numArr[2], numArr[3], numArr[4]);
	
	numArr[0] = 0, numArr[1] = 0, numArr[2] = 0, numArr[3] = 0, numArr[4] = 0;
	for (i = 0 ; i < 100000 ; i++) {
		rst = rand() % 5;
		numArr[rst] = numArr[rst] + 1;
	}	 
	printf("1 : %d, 2 : %d, 3 : %d, 4 : %d, 5 : %d\n", numArr[0], numArr[1], numArr[2], numArr[3], numArr[4]);
	
	numArr[0] = 0, numArr[1] = 0, numArr[2] = 0, numArr[3] = 0, numArr[4] = 0;
	for (i = 0 ; i < 100000 ; i++) {
		rst = rand() % 5;
		numArr[rst] = numArr[rst] + 1;
	}	 
	printf("1 : %d, 2 : %d, 3 : %d, 4 : %d, 5 : %d\n", numArr[0], numArr[1], numArr[2], numArr[3], numArr[4]);
	
	numArr[0] = 0, numArr[1] = 0, numArr[2] = 0, numArr[3] = 0, numArr[4] = 0;
	for (i = 0 ; i < 100000 ; i++) {
		rst = rand() % 5;
		numArr[rst] = numArr[rst] + 1;
	}	 
	printf("1 : %d, 2 : %d, 3 : %d, 4 : %d, 5 : %d\n", numArr[0], numArr[1], numArr[2], numArr[3], numArr[4]);
	
	numArr[0] = 0, numArr[1] = 0, numArr[2] = 0, numArr[3] = 0, numArr[4] = 0;
	for (i = 0 ; i < 100000 ; i++) {
		rst = rand() % 5;
		numArr[rst] = numArr[rst] + 1;
	}	 
	printf("1 : %d, 2 : %d, 3 : %d, 4 : %d, 5 : %d\n", numArr[0], numArr[1], numArr[2], numArr[3], numArr[4]);


	printf("==가위바위보==\n");
	int input, comInput, rrst;
	int win = 0, draw= 0, lose = 0;
	
	char* arrr[3] = {"가위","바위","보"};
	while((win + draw + lose) < 10) {
		printf("가위 1, 바위 2, 보 3 : ");
		scanf("%d",&input);
		if(input > 3 || input < 1) {
			printf("잘못 입력\n"); 
			continue;
		}
		comInput = rand() % 3 + 1;
		printf("나: %-4s, 컴퓨터 : %-4s   | ",arrr[input-1], arrr[comInput-1]); 
		rrst = whoWin(input, comInput);
		
		if (rrst == 1) printf(" 승리\n"), win++;
		else if (rrst == 0) printf(" 비김\n"), draw++;
		else if (rrst == -1) printf(" 패배\n"), lose++;
		 
	}
	
	printf("승 : %d \t\t무 : %d \t\t패 : %d\n", win, draw, lose);
	
	return 0;
}
