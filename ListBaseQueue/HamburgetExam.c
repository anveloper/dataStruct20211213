#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ListBaseQueue.h"

#define CUSTOMER_TERM 30

#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2

#define CHE_TERM 45
#define BUL_TERM 60
#define DUB_TERM 80

// 1�ð� ���� �ֹ��� �����鼭 ���ÿ� �����Ѵٸ� �󸶳� �ֹ��� ó���� �� ������?
 
int main(void)
{
	int makeProc = 0;
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int cheMake = 0, bulMake = 0, dubMake = 0;
	int sec;
	
	Queue que;
	
	QueueInit(&que);
	srand(time(NULL)); // 1970 1�� 1�Ϻ��� ������� �帥 �ð� �ʴ����� ��ȯ(�Ź� �ٲ�)
	// srand�� ������ ��¥ ���� ���� -> srand�� ���� rand �Լ� ���� �ٲ� 
	
	for(sec=0; sec<3600; sec++) // for���� 1ȸ���� 1���� �ð� �帧�� �ǹ� 
	{
		if(sec % CUSTOMER_TERM == 0) // �ش� ������ ���� 1ȸ �ֹ��Ҷ����� �۵� 
		{
			// �ֹ� ���� 
			switch(rand() % 3) // ���� ����, ������ ����� 0, 1, 2 �� �ϳ� 
			{
				///
				case CHE_BUR:
					Enqueue(&que, CHE_TERM);
					cheOrder++;
					break;
				case BUL_BUR:
					Enqueue(&que, BUL_TERM);
					bulOrder++;
					break;
				case DUB_BUR:
					Enqueue(&que, DUB_TERM);
					dubOrder++;
					break;
				///
			}
		}
		
		// ���� ����
		if(makeProc<=0 && !QIsEmpty(&que)) {
			makeProc = Dequeue(&que); // ������
			
			switch(makeProc)
			{
				case CHE_TERM:
					cheMake++;
					break;
				case BUL_TERM:
					bulMake++;
					break;
				case DUB_TERM:
					dubMake++;
					break;
			}
		}
		
		makeProc--; 
	}
	
	printf("Simulation Report!\n");
	printf(" - ġ����� �ֹ���: %d, ���� �ֹ� ó����: %d\n", cheOrder, cheMake);
	printf(" - �Ұ����� �ֹ���: %d, ���� �ֹ� ó����: %d\n", bulOrder, bulMake);
	printf(" - ������� �ֹ���: %d, ���� �ֹ� ó����: %d\n", dubOrder, dubMake);
	
	return 0;
}
