#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int PointListMain(void) {
	List list;
	Point comPos;
	Point* ppos;
	
	ppos = (Point*)malloc(sizeof(Point)); // 초기화 
	SetPointPos(ppos, 3, 1); // ppos에 값 입력 
	LInsert(&list, ppos); // list에 ppos 저장값을 저장 
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 4, 1);
	LInsert(&list, ppos);
	
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 4, 2);
	LInsert(&list, ppos);
		
	// 전체 데이터 출력
	printf("== 현재 저장된 데이터 ==\n"); 
	if(LFirst(&list, &ppos)) {
		ShowPointPos(ppos);
		while(LNext(&list, &ppos)) {
			ShowPointPos(ppos);
		}
	}
	
	// xpos가 4인 데이터 모두 삭제
	
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
		
	// 전체 데이터 출력
	printf("== 현재 저장된 데이터 ==\n"); 
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
	
	// 전체 데이터 조회 
	printf("===전체 데이터 조회===\n");
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		while(LNext(&list, &data)) {
			printf("%d ", data);
	 	}
	}
	//데이터의 합 구하 기
	
	printf("\n");
	printf("===전체 데이터의 합===\n");
	int sum = 0 ;
	if(LFirst(&list, &data)) {
		sum += data;
		while(LNext(&list, &data)) {
			sum += data;
	 	}
	}
	printf("%d\n",sum);
	
	// 2의 배수와 3의 배수 삭제하기
	
	printf("===2, 3의 배수 삭제===\n\n");
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
	
	printf("===전체 데이터 조회===\n");
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		while(LNext(&list, &data)) {
			printf("%d ", data);
	 	}
	}
	
	return 0;
}
*/
