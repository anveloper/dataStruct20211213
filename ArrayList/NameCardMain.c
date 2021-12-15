#include <stdio.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void){
	List list;
	NameCard comNameCard;
	NameCard* nameCard;
	ListInit(&list);
	
	nameCard = (NameCard*)malloc(sizeof(NameCard));
	nameCard = MakeNameCard("�ֻ���", "010-1111-1111");
	LInsert(&list, nameCard);
	
	nameCard = (NameCard*)malloc(sizeof(NameCard));
	nameCard = MakeNameCard("�����", "010-2222-2222");
	LInsert(&list, nameCard);
	
	nameCard = (NameCard*)malloc(sizeof(NameCard));
	nameCard = MakeNameCard("�ڻ���", "010-3333-3333");
	LInsert(&list, nameCard);
	// ��� ���� ���
	printf("== ��� ����� ���� ��� ==\n"); 
	if(LFirst(&list,&nameCard)) {
		ShowNameCardInfo(nameCard);		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		} 
	} 
	
	// �ڻ����� ������ ���
	printf("== �ڻ����� ������ ��� ==\n"); 
	if(LFirst(&list,&nameCard)) {
		if(NameCompare(nameCard,"�ڻ���") == 0) {
			ShowNameCardInfo(nameCard);		
		}
		while(LNext(&list, &nameCard)) {
			if(NameCompare(nameCard,"�ڻ���") == 0) {
				ShowNameCardInfo(nameCard);		
			}
		} 
	} 
	

	
	return 0;
}
