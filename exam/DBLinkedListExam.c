#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist)
{
	// ����� ���Ḯ��Ʈ �ʱ�ȭ 
	plist->head = NULL;
	plist->numOfData = 0;
}
void LInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	// �����ʹ� ���ʺ��� ���Ե˴ϴ�.
	// �� ���� head�� �˴ϴ�. 
	newNode->next = plist->head;
	
	// head�� �������� �ʴ´ٸ�(ó�� ���Ե� ���̶��) head�� prev�� �� ��带 ����ŵ�ϴ�. 
	if(plist->head != NULL) {
		plist->head->prev = newNode;	
	}
	
	// �� ���� ���� �տ� ���ԵǹǷ� prev�� NULL�Դϴ�.
	// �� ��尡 ���ԵǸ� head�� ��ġ�� �� ����� ��ġ�� �����մϴ�. 
}

int LFirst(List * plist, Data * pdata)
{
	// head�� NULL�̶�� ���Ḯ��Ʈ�� �����Ͱ� ���� ���� ���մϴ�. 
	if() {
		return FALSE;
	}
	
	// cur�� head���� ��ȸ�մϴ�.
	// ��ȸ�� �����ʹ� pdata �޸� ������ �����մϴ�. 
	
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	// cur ������ ���� �����Ͱ� ���ٸ� ���Ḯ��Ʈ�� �����Ͱ� ���� ���� ���մϴ�. 
	if() {
		return FALSE;
	}
	
	// cur�� ��ġ�� ���� ��ĭ �ڷ� ������ϴ�. (���� �����͸� ����ŵ�ϴ�. )
	// ����� cur ��ġ�� �����͸� �����Ͽ� pdata �޸� ������ �����մϴ�. 
	
	return TRUE;
}

int LPrevious(List * plist, Data * pdata) // LNext �Լ��� �ݴ� �������� ��� ����
{
	// cur�� ���� ��ġ�� �������� �ʴ� ��� ���̻� ���������� ������ �����Ͱ� ������ ���մϴ�. 
	if() {
		return FALSE;
	}
	
	// ���� ��ġ�� ��ĭ ������ ���ϴ�. (���� �����͸� ����ŵ�ϴ�.) 
	// ����� cur ��ġ�� �����͸� �����Ͽ� pdata �޸� ������ �����մϴ�. 
	
	return TRUE;
}

int LCount(List * plist)
{
	return plist->numOfData;
}
