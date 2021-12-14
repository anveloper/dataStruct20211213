#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main(void){
	
	
	
	
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
