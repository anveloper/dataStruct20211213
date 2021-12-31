#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

// ����� ���Ḯ��Ʈ�� ������ ��尡 ù��° ��带 ������ ��� ������ ����Ǿ� �ִ� ���¸� ���մϴ�.
// �ּ� �Ʒ� �κп� �ڵ带 �Է����ֽø� �˴ϴ�. 
void ListInit(List * plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}
void LInsert(List * plist, Data data) // ������ ��带 �߰�
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL) {
		// �����͸� ó�� �����ϸ� ������ ���ο� ��尡 �˴ϴ�. 
		// ���ο� ���� �ڱ� �ڽ��� ����ŵ�ϴ�. 

	} else {
		// ù��° �����ʹ� tail�� Ȱ���Ͽ� ǥ���մϴ�.
		// ���ο� ���� ù��° �����͸� ����ŵ�ϴ�.
		// ù��° �����ʹ� ���ο� ��尡 �˴ϴ�.
		// ������ �ٽ� ���ο� ��尡 �˴ϴ�. 

	}
	
	// ����Ʈ�� ������ ������ �����մϴ�. 
}
void LInsertFront(List * plist, Data data) // �Ӹ��� ��带 �߰�
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL) {
		// �����͸� ó�� �����ϸ� ������ ���ο� ��尡 �˴ϴ�. 
		// ���ο� ���� �ڱ� �ڽ��� ����ŵ�ϴ�. 
		
	}
	else {
		// ù��° �����ʹ� tail�� Ȱ���Ͽ� ǥ���մϴ�.
		// ���ο� ���� ù��° �����͸� ����ŵ�ϴ�. 
		// ù��° �����ʹ� ���ο� ��尡 �˴ϴ�. 
		
	}
	
	// ����Ʈ�� ������ ������ �����մϴ�. 
}

int LFirst(List * plist, Data * pdata)
{
	// ������ �������� �ʴ´ٸ� FALSE�� �����մϴ�. 
	if() {
		return FALSE;
	}
	
	// before�� ������ �˴ϴ�.
	// cur�� ù��° �����Ͱ� �˴ϴ�.
	// ù��° �����ʹ� tail�� Ȱ���Ͽ� ǥ���մϴ�. 
	// before�� ������ ����� ������ ù��° �����͸� cur�� ����ϱ� ���ؼ��Դϴ�. 
	
	
	// �����͸� pdata ������ ������ �����մϴ�.
	
	return TRUE; 
}
int LNext(List * plist, Data * pdata)
{
	// ������ �������� �ʴ´ٸ� FALSE�� �����մϴ�. 
	if(plist->tail == NULL) {
		return FALSE;
	}
	
	// LNext�� �ҷ��Դٴ� ���� LFirst �Լ��� ����߰� ���� �����Ͱ� �����ϴ� ��Ȳ�Դϴ�. 
	// before�� ���� cur�� �ּҰ� �˴ϴ�.
	// cur�� ���� �����Ͱ� �˴ϴ�. 

	
	// �����͸� pdata ������ ������ �����մϴ�.
	
	return TRUE;
}
Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data rdata = rpos->data;
	
	// rpos�� ������ �������� ��� �ΰ��� ����� ���� ����ó�� �ؾ� �մϴ�.
	// (TMI)���� ��带 ���� ��� �ش� ����ó���� ���ص� �˴ϴ�.
	// ���� 1: ������ �����Ͱ� ������ ��ġ�� ���ÿ� ������ ���� �����Ͷ�� NULL�� �����մϴ�.
	// ���� 2: ������ �����Ͱ� ������ ��ġ��� tail�� �ּҸ� before�� �ּҷ� �ٲ��ݴϴ�. 
	if(rpos == plist->tail) {
		if(plist->tail == plist->tail->next) {
			
		} else {
			
		}
	}
	
	// �ش� ���� ó���� �Ѵٸ� ��� ����� ���� ������ ������ �����ϰ� ����˴ϴ�.
	// ���� ó���� ���� ���� ��尡 ������ ���� ����� ���� ��带 ����ŵ�ϴ�.
	// ���� ��尡 �����Ǿ����Ƿ� ���� ����� ��ġ�� ���� ���� �������ݴϴ�. 
	
	
	// ������ ����� �޸𸮸� �����մϴ�.
	// ����Ʈ�� ������ ���� �����մϴ�.
	// ������ �����͸� ��ȯ�մϴ�. 
	
	 
	// (TMI) ������ �������� ����� �� �����ϴ�. before�� ��ġ ������ �ʿ��ϱ� �����Դϴ�.
	// ���� LFirst �Ǵ� LNext ȣ�� �� �ּҸ� ������ �� ����ؾ� �մϴ�. 
}
int LCount(List * plist)
{
	return plist->numOfData;
}
