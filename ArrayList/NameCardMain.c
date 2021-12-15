#include <stdio.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void){
	List list;
	NameCard comNameCard;
	NameCard* nameCard;
	ListInit(&list);
	
	nameCard = (NameCard*)malloc(sizeof(NameCard));
	nameCard = MakeNameCard("최사장", "010-1111-1111");
	LInsert(&list, nameCard);
	
	nameCard = (NameCard*)malloc(sizeof(NameCard));
	nameCard = MakeNameCard("김사장", "010-2222-2222");
	LInsert(&list, nameCard);
	
	nameCard = (NameCard*)malloc(sizeof(NameCard));
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
	

	
	return 0;
}
