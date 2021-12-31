#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // ���� ������ �ʱ�ȭ, head�� DMY�� ����Ŵ 
	plist->head->next = NULL; // ���� ������ NULL�� �ʱ�ȭ 
	plist->comp = NULL;
	plist->numOfData = 0; 
}

void FInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = plist->head->next;
	plist->head->next = newNode;
	
	(plist->numOfData)++;
}

void SInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	Node * pred = plist->head; // pred�� ���̳�带 ����Ŵ, head�� ���̳�带 ����Ű�Ƿ� 
	newNode->data = data;
	
	while(pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		// plist->comp(data, pred->next->data) ���� pred->next->data�� ���� ������ ������
		// �ű� �Էµ� ������ < ���� ������ �������̸� pred�� ��ĭ ������ �̵�
		// �����Ͽ� �����ϱ� ���ؼ� 
		pred = pred->next;
	}
	
	newNode->next = pred->next; // �� ���� ������ ���� �����͸� ����Ŵ 
	pred->next = newNode; // ������� ���ο� ��带 ����Ű�鼭 ���̿� ���ο� ������ �߰� 
	
	(plist->numOfData)++;
}

void LInsert(List * plist, LData data)
{
	if(plist->comp == NULL)
	{
		FInsert(plist, data);
	} else {
		SInsert(plist, data);
	}
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->head->next == NULL)
	{
		return FALSE;
	}
	
	plist->before = plist->head; // ù before �ּ� �ʱ�ȭ 
	plist->cur = plist->head->next; // ù cur �ּ� �ʱ�ȭ 

	*pdata = plist->cur->data;
	return TRUE; 
}

int LNext(List * plist, LData * pdata)
{
	if(plist->cur->next == NULL)
	{
		return FALSE;
	}
	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node * rpos = plist->cur;
	LData rdata = rpos->data;
	
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	
	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp; // comp��� �Լ��� ����� �� �ֵ��� ó���� �� 
}
