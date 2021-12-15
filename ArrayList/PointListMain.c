#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int PointListMain(void) {
	List list;
	Point comPos;
	Point* ppos;
	
	ppos = (Point*)malloc(sizeof(Point)); // �ʱ�ȭ 
	SetPointPos(ppos, 3, 1); // ppos�� �� �Է� 
	LInsert(&list, ppos); // list�� ppos ���尪�� ���� 
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 4, 1);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 4, 2);
	LInsert(&list, ppos);
		
	// ��ü ������ ���
	printf("== ���� ����� ������ ==\n"); 
	if(LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);
		}
	}
	
	// xpos�� 4�� ������ ��� ����
	
	comPos.xpos = 4;
	comPos.ypos = -1;
	if(LFirst(&list, &ppos)) {
		if(PointComp(ppos, &comPos) == 1) {
			ppos = LRemove(&list);
			free(ppos);
		}
		while(LNext(&list, &ppos)) {
			if(PointComp(ppos, &comPos) == 1) {
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}	
		
	// ��ü ������ ���
	printf("== ���� ����� ������ ==\n"); 
	if(LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);
		}
	}
	
	return 0;
}


/*
int main(void) {
	List list;
	int data;	
	ListInit(&list);
	
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);
	LInsert(&list, 9);
	
	// ��ü ������ ��ȸ 
	printf("===��ü ������ ��ȸ===\n");
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		while(LNext(&list, &data)) {
			printf("%d ", data);
	 	}
	}
	//�������� �� ���� ��
	
	printf("\n");
	printf("===��ü �������� ��===\n");
	int sum = 0 ;
	if(LFirst(&list, &data)) {
		sum += data;
		while(LNext(&list, &data)) {
			sum += data;
	 	}
	}
	printf("%d\n",sum);
	
	// 2�� ����� 3�� ��� �����ϱ�
	
	printf("===2, 3�� ��� ����===\n\n");
	if(LFirst(&list, &data)){
		if (data % 2 == 0 || data % 3 == 0){
			LRemove(&list);
		} 
		while(LNext(&list, &data)){
			if (data % 2 == 0 || data % 3 == 0){
				LRemove(&list);
			}
		}
	} 
	
	printf("===��ü ������ ��ȸ===\n");
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		while(LNext(&list, &data)) {
			printf("%d ", data);
	 	}
	}
	
	return 0;
}
*/
