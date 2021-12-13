#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100

typedef int LData;

typedef struct _ArrayList{
	LData arr[LIST_LEN];// ����Ʈ ����� 
	int numOfData;		// ����� �������� �� 
	int curPosition;	// ������ ������ġ 
} ArrayList;

typedef ArrayList List; 
//typedef LinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, LData* data);

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);

#endif
