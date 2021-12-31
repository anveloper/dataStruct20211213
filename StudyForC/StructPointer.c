#include <stdio.h>

struct point
{
	int xpos;
	int ypos;
};

int main(void)
{
	struct point pos1 = {1, 2}; // point ����ü pos1 �ʱ�ȭ
	struct point pos2 = {100, 200}; // point ����ü pos1 �ʱ�ȭ
	struct point * pptr = &pos1; // point ����ü�� ������ pptr 
	
	(*pptr).xpos += 4; // (*pptr) ���� ��� 
	(*pptr).ypos += 5;
	printf("[%d, %d] \n", (*pptr).xpos, (*pptr).ypos);
	
	pptr = &pos2;
	pptr->xpos += 1;
	pptr->ypos += 2;
	printf("[%d, %d] \n", pptr->xpos, pptr->ypos);
	
	return 0;
}

// typedef ����

//typedef struct _point
//{
//	int xpos;
//	int ypos;
//} Point;
 