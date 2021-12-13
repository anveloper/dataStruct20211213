#include "ArrayList.h"

void ListInit(List* plist) {
	(plist->numOfData) = 0; // 데이터의 최초 갯수는 0 
	(plist->curPosition) = -1; // 첫번째 인덱스 값은 0이기 때문에 -1로 초기화 
}

void LInsert(List* plist, LData* data) {
	if(plist->numOfData >= LIST_LEN){
		printf("저장이 불가능 합니다.\n");
		return;
	}	
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata) {
	if(plist->numOfData==0) {
		return FALSE;
	}
	
	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	
	return TRUE;
}
int LNext(List* plist, LData* pdata) {
	if(plist->curPosition >= (plist->numOfData) - 1) {
		return FALSE;
	}	
	
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
}

LData LRemove(List* plist) {
	int rpos = plist->curPosition;
	int size = plist->numOfData;
	LData rdata = plist->arr[rpos];
	
}


int LCount(List* plist);
