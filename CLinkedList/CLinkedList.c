#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
	
}
void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	} else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode; // tail을 직접 사용하는 경우는 tail 자기자신이 이동할때만 사용 
	} // 즉 tail로 삽입할때만 tail값을 직접 사용한다. 
	(plist->numOfData)++;
}
void LInsertFront(List* plist, Data data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	} else {
		newNode->next = plist->tail->next;
		plist->tail->next= newNode;  // tail의 next로 무조건 바라보고, tail은 스스로가 바뀔때만 사용한다.
	}
	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata) {
	if(plist->tail == NULL) return FALSE;
	
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	
	*pdata = plist->cur->data;
	
	return TRUE; 
}
int LNext(List* plist, Data* pdata) {
	if(plist->tail == NULL) return FALSE;
	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;
	
	return TRUE;
}

Data LRemove(List* plist) {
	Node* rpos = plist->cur;
	Data rdata = rpos->data;
	//예외 1 : 삭제할 데이터가 마지막 위치이면서 마지막남은 데이터
	//예외 2 : 삭제할 데이터가 마지막 위치라면 
	if(rpos == plist->tail) {
		if(plist->tail == plist->tail->next) {
			plist->tail = NULL;
		} else {
			plist->tail = plist->before;
		}
	}
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	free(rpos);
	(plist->numOfData)--;
	return rdata;
}
int LCount(List* plist){
	return plist->numOfData;
}

