#include <stdio.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void){
	List list;
	NameCard comNameCard;
	NameCard* nameCard;
	ListInit(&list);
	int cmdFlag = 0;
	int i = 0; 
	char name[10];
	char phone[10];
	// 예제 데이터 
	nameCard = MakeNameCard("테스트", "000-1111-0000");
	LInsert(&list, nameCard);
	nameCard = MakeNameCard("스트테", "000-2222-0000");
	LInsert(&list, nameCard);
	nameCard = MakeNameCard("트테스", "000-3333-0000");
	LInsert(&list, nameCard);
	nameCard = MakeNameCard("홍길동", "000-3536-0000");
	LInsert(&list, nameCard);
	nameCard = MakeNameCard("백두산", "000-3343-0600");
	LInsert(&list, nameCard);
	nameCard = MakeNameCard("계족산", "000-3333-0000");
	LInsert(&list, nameCard);
	
	while(1){
		cmdFlag = 0;
		i = 0;
		printf("***** MENU *****\n");
		printf("1. Insert		: 데이터를 추가\n");
		printf("2. Search		: 데이터를 검색, 이름을 기준으로 검색\n");
		printf("3. Modify		: 데이터를 수정, 이름을 기준으로 수정\n");
		printf("4. Delete		: 데이터를 삭제, 이름을 기준으로 삭제\n");
		printf("5. Print All		: 모든 데이터를 출력\n");
		printf("6. Count		: 현재 데이터의 수를 반환\n");
		printf("7. Exit			: 콘솔 프로그램을 종료\n");
		printf("> Choose the item : ");
		scanf("%d",&cmdFlag); 
		
		if(cmdFlag == 7){
			printf("[ EXIT ]\n");
			break;
		} else if (cmdFlag == 1){ // 문제점.. 이름이 같으면 어떻게 구분할 것인지 
			NameCard newName; 
			printf("[ INSERT ]\n");
			printf("> 이름 : ");
			scanf("%s", &newName.name);
			printf("> 연락처 : ");
			scanf("%s", &newName.phone);
			
			nameCard = MakeNameCard(newName.name, newName.phone);
			LInsert(&list, nameCard);
			printf("* %s 등록이 완료되었습니다.\n", newName.name);
			printf("\n");
		} else if (cmdFlag == 2){ // 검색된 결과 없을때 (해결) 
			printf("[ SEARCH ]\n");
			printf("> 이름 : ");
			scanf("%s", name);
			i = LCount(&list); //검색 마다 감소 시킬 비교 값 
			if(LFirst(&list,&nameCard)) {
				if(NameCompare(nameCard, name) == 0) {
					ShowNameCardInfo(nameCard);
					i--;
				}
				while(LNext(&list, &nameCard)) {
					if(NameCompare(nameCard, name) == 0) {
						ShowNameCardInfo(nameCard);		
						i--;
					}
				} 
			} 
			if(i == LCount(&list)){  // 검색된 내용이 없을때 표시하기 
				printf("* 해당하는 이름이 없습니다.\n");
			} else {
				printf("* %s 검색이 완료되었습니다.\n", name);
			} 			
			printf("\n");			
		} else if (cmdFlag == 3){
			printf("[ MODIFY ]\n");
			printf("> 이름 : ");
			scanf("%s", name);
			
			i = LCount(&list); // 이름이 있는지 확인하는 부분 
			if(LFirst(&list,&nameCard)) {
				if(NameCompare(nameCard, name) == 0) {
					i--;
				}
				while(LNext(&list, &nameCard)) {
					if(NameCompare(nameCard, name) == 0) {
						i--;
					}
				} 
			} 
			if(i == LCount(&list)){
				printf("* 해당하는 이름이 없습니다.\n\n");
				continue; 
			} // 이름이 없으면 continue 
			
			printf("> 수정할 연락처 : ");
			scanf("%s", phone);
			if(LFirst(&list,&nameCard)) {
				if(NameCompare(nameCard, name) == 0) {
					ChangePhoneNumber(nameCard, phone);		
				}
				while(LNext(&list, &nameCard)) {
					if(NameCompare(nameCard,name) == 0) {
						ChangePhoneNumber(nameCard, phone);		
					}
				} 
			} 
			printf("* %s 수정이 완료되었습니다.\n", name);
		
			printf("\n");	
		} else if (cmdFlag == 4){
			printf("[ DELETE ]\n");
			printf("> 이름 : ");
			scanf("%s", name);
			
			i = LCount(&list); // 이름이 있는지 확인하는 부분 
			if(LFirst(&list,&nameCard)) {
				if(NameCompare(nameCard, name) == 0) {
					i--;
				}
				while(LNext(&list, &nameCard)) {
					if(NameCompare(nameCard, name) == 0) {
						i--;
					}
				} 
			} 
			if(i == LCount(&list)){
				printf("* 해당하는 이름이 없습니다.\n\n");
				continue; 
			} // 이름이 없으면 continue 
			
			if(LFirst(&list,&nameCard)) {
				if(NameCompare(nameCard, name) == 0) {
					LRemove(&list);
					free(nameCard);		
				}
				while(LNext(&list, &nameCard)) {
					if(NameCompare(nameCard, name) == 0) {
						LRemove(&list);		
						free(nameCard);	
					}
				} 
			} 
			printf("* %s 삭제가 완료되었습니다.\n", name);
			
			printf("\n");
		} else if (cmdFlag == 5){
			printf("[ PRINT All ]\n");
			
			if(LFirst(&list,&nameCard)) {
				ShowNameCardInfo(nameCard);		
				while(LNext(&list, &nameCard)) {
					ShowNameCardInfo(nameCard);
				} 
			} 
			
			printf("\n");
		} else if (cmdFlag == 6){
			printf("[ COUNT ]\n");
			
			printf("현재 데이터의 수 : %d\n", LCount(&list));
			printf("\n");
		} else {
			printf("**** 잘못 입력하였습니다.****\n");
		}
		while (getchar() != '\n'); 
		//int형 정보를 받아야 할때, 범위 외 다른 정보가 들어오게 되면, 정보 추출에 실패하여 마지막에 입력된 \n가 반복되게 된다. 
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
