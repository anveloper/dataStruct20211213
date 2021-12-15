#ifndef __ARRAY_LIST_H__ // ArrayList.h ������ �������� �ʴ� ��쿡�� ������ �� �ֵ��� �ϴ� ��ũ�� 
#define __ARRAY_LIST_H__

#define TRUE 1 // C������ TRUE��� ������ �����ϴ�. �׷��� ��ũ�η� define ���� ���Դϴ�. 
#define FALSE 0

#define LIST_LEN 100 // ����Ʈ�� ũ��� 100���� �����س��ҽ��ϴ�. 
//typedef int LData; // ������ Data�� �� ���Դϴ�. typedef�� ��Ī�� �ٿ��ִ� �� -> LDate �ڷ����� int�� ��ǻ�Ͱ� �ν��մϴ�

#include "Point.h"
typedef Point * LData;

//#include "NameCard.h"
//typedef NameCard * LData;

typedef struct __ArrayList // �迭 ��� ����Ʈ�� ������ ����ü 
{
	LData arr[LIST_LEN]; // ����Ʈ �����
	int sizeOfData; // ����� �������� ��
	int curPosition; // ������ ������ġ 
} ArrayList; // ������ ����� ����ü �̸� 

typedef ArrayList List; // ArrayList -> List �̸����� ����ϰڴٰ� ����մϴ�.

void ListInit(List * plist); // �ʱ�ȭ ��� 
void LInsert(List * plist, LData data); // ������ ���� ��� 

int LFirst(List * plist, LData * pdata); // ù ������ ���� ��� 
int LNext(List * plist, LData * pdata); // �ι�° ������ ���� ��� 

LData LRemove(List * plist); // ������ ���� ��� 
int LCount(List * plist); // �������� �� ���� ���ϴ� ��� 

#endif
