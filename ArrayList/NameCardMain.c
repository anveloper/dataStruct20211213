#include <stdio.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void){
	List list;
	NameCard comNameCard;
	NameCard* nameCard;
	ListInit(&list);
	int cmdFlag = 0;
	while(1){
		cmdFlag = 0;
		printf("***** MENU *****\n");
		printf("1. Insert		: 데이터를 추가\n");
		printf("2. Search		: 데이터를 검색, 이름을 기준으로 검색\n");
		printf("3. Modify		: 데이터를 수정, 이름을 기준으로 수정\n");
		printf("4. Delete		: 데이터를 삭제, 이름을 기준으로 삭제\n");
		printf("5. Print All		: 모든 데이터를 출력\n");
		printf("6. Count		: 현재 데이터의 수를 반환\n");
		printf("7. Exit			: 콘솔 프로그램을 종료\n");
		printf("* Choose the item : ");
		scanf("%d",&cmdFlag); 
		
		if(cmdFlag == 7){
			printf("[ EXIT ]\n");
			break;
		} else if (cmdFlag == 1){
			printf("[ Insert ]\n");
			
			
		} else if (cmdFlag == 2){
			printf("[ Search ]\n");
			
			
		} else if (cmdFlag == 3){
			printf("[ Modify ]\n");
			
			
		} else if (cmdFlag == 4){
			printf("[ Delete ]\n");
			
			
		} else if (cmdFlag == 5){
			printf("[ Print All ]\n");
			
			
		} else if (cmdFlag == 6){
			printf("[ Count ]\n");
			
			
		} else {
			printf("* 잘못 입력하였습니다.\n");
		}
		
		
		
	}
	
	
	return 0;
}
/*
int main(void){
	List list;
	NameCard comNameCard;
	NameCard* nameCard;
	ListInit(&list);
	
	nameCard = MakeNameCard("최사장", "010-1111-1111");
	LInsert(&list, nameCard);
	
	nameCard = MakeNameCard("김사장", "010-2222-2222");
	LInsert(&list, nameCard);
	
	nameCard = MakeNameCard("박사장", "010-3333-3333");
	LInsert(&list, nameCard);
	
	// 모든 정보 출력
	printf("== 모든 사람의 정보 출력 ==\n"); 
	if(LFirst(&list,&nameCard)) {
		ShowNameCardInfo(nameCard);		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		} 
	} 
	
	// 박사장의 정보만 출력
	printf("== 박사장의 정보만 출력 ==\n"); 
	if(LFirst(&list,&nameCard)) {
		if(NameCompare(nameCard,"박사장") == 0) {
			ShowNameCardInfo(nameCard);		
		}
		while(LNext(&list, &nameCard)) {
			if(NameCompare(nameCard,"박사장") == 0) {
				ShowNameCardInfo(nameCard);		
			}
		} 
	} 
	
	// 박사장의 정보 변경 
	printf("== 박사장의 정보만 변경 ==\n"); 
	if(LFirst(&list,&nameCard)) {
		if(NameCompare(nameCard,"박사장") == 0) {
			ChangePhoneNumber(nameCard, "010-9999-9999");		
		}
		while(LNext(&list, &nameCard)) {
			if(NameCompare(nameCard,"박사장") == 0) {
				ChangePhoneNumber(nameCard, "010-9999-9999");		
			}
		} 
	} 
	
	// 모든 정보 출력
	printf("== 모든 사람의 정보 출력 ==\n"); 
	if(LFirst(&list,&nameCard)) {
		ShowNameCardInfo(nameCard);		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		} 
	} 
	
	// 박사장의 정보 삭제 
	if(LFirst(&list,&nameCard)) {
		if(NameCompare(nameCard,"박사장") == 0) {
			LRemove(&list);
			free(nameCard);		
		}
		while(LNext(&list, &nameCard)) {
			if(NameCompare(nameCard,"박사장") == 0) {
				LRemove(&list);		
				free(nameCard);	
			}
		} 
	} 
	
	// 모든 정보 출력
	printf("== 모든 사람의 정보 출력 ==\n"); 
	if(LFirst(&list,&nameCard)) {
		ShowNameCardInfo(nameCard);		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		} 
	} 
	printf("현재 데이터의 수 : %d\n",LCount(&list));
	
	return 0;
}
*/
