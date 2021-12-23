/*
#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"


int main(void) {
	List list;
	ListInit(&list);
	int data;
	
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);
	LInsert(&list, 9);
	LInsert(&list, 10);
	LInsertFront(&list, 5);
	LInsertFront(&list, 4);
	LInsertFront(&list, 3);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	
	while(1) {
		printf("자연수 입력 : ");
		scanf("%d",&data);
		
		if(data < 1) break;
		LInsert(&list, data);
		LInsertFront(&list, data);
	}
	
	
	printf("=== 1순환 출력===\n");
	int cnt = LCount(&list);	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		while(LNext(&list, &data) && cnt > 1) {
			printf("%d ", data);
			cnt--;
		}
	}
	
	printf("\n=== 30회 출력===\n");	
	cnt = 30;	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		while(LNext(&list, &data) && cnt > 1) {
			printf("%d ", data);
			cnt--;
		}
	}
	
	printf("\n=== 2의 배수 삭제 ");
	cnt = LCount(&list);
	if(LFirst(&list, &data)) {
		if(data % 2 == 0){
			LRemove(&list);
		} 
		while(LNext(&list, &data) && cnt > 1) {
			if(data % 2 == 0){
				LRemove(&list);
			} 
			cnt--;
		}
	}
	
	printf("/ 20회 출력===\n");
	cnt = 20;	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		while(LNext(&list, &data) && cnt > 1) {
			printf("%d ", data);
			cnt--;
		}
	}
	
	printf("\n=== 1순환 출력===\n");
	cnt = LCount(&list);	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		while(LNext(&list, &data) && cnt > 1) {
			printf("%d ", data);
			cnt--;
		}
	}
	
	return 0;
}
*/
