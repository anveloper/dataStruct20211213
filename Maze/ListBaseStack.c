#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack) // ���� �ʱ�ȭ
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack) // ������ ������� Ȯ�� 
{
	if(pstack->head == NULL)
	{
		return TRUE;
	} else {
		return FALSE;
	}
}

void SPush(Stack * pstack, Data data) // ������ ������ ����
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->next = pstack->head;
	
//	printf("[���� �߰� %d, %d] > ", data.x, data.y);
	
	pstack->head = newNode;
}

Data SPop(Stack * pstack) // ������ �ֻ�� �� ��ȯ �� ����
{
	Data rdata; // ���� ������ 
	Node * rnode; // ���� �������� �ּҰ�
	
	if(SIsEmpty(pstack))
	{
		printf("Stack Empty!");
		exit(-1);
	}
	
	rdata = pstack->head->data;
	rnode = pstack->head;
	
	pstack->head = pstack->head->next;
	
//	printf("[���� ���� %d, %d] > ", rdata.x, rdata.y);
	
	free(rnode);
	
	return rdata;
}

Data SPeek(Stack * pstack) // ������ �ֻ�� ������ ��ȯ
{
	if(SIsEmpty(pstack))
	{
		printf("Stack Empty!");
		exit(-1);
	}
		
	return pstack->head->data;
}
