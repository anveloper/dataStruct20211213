#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node{
	Data data;
	struct _node* next;
	struct _node* prev;
	
} Node;

typedef struct _DBLinkedList{
	Node* head;
	Node* cur;
	int numOfData;
	
} DBlinkedList;

typedef DBlinkedList List;

void ListInit(List* plist);
void LInsert(List* plsit, Data data);

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
int LPrevious(List* plist, Data* pdata);

int LCount(List* plist);

#endif
