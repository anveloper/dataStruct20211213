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
	printf("������ ���� : 0���� %d\n", RAND_MAX);

	srand(time(NULL));
	
	printf("==�ֻ��� Ȯ���� ������?==\n");
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


	printf("==����������==\n");
	int input, comInput, rrst;
	int win = 0, draw= 0, lose = 0;
	
	char* arrr[3] = {"����","����","��"};
	while((win + draw + lose) < 10) {
		printf("���� 1, ���� 2, �� 3 : ");
		scanf("%d",&input);
		if(input > 3 || input < 1) {
			printf("�߸� �Է�\n"); 
			continue;
		}
		comInput = rand() % 3 + 1;
		printf("��: %-4s, ��ǻ�� : %-4s   | ",arrr[input-1], arrr[comInput-1]); 
		rrst = whoWin(input, comInput);
		
		if (rrst == 1) printf(" �¸�\n"), win++;
		else if (rrst == 0) printf(" ���\n"), draw++;
		else if (rrst == -1) printf(" �й�\n"), lose++;
		 
	}
	
	printf("�� : %d \t\t�� : %d \t\t�� : %d\n", win, draw, lose);
	
	return 0;
}
