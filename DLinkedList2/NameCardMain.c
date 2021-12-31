#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "NameCard.h"

int NameCardMain(void)
{
	List list;
	LData nameCard;
	ListInit(&list);
	
	nameCard = MakeNameCard("�ֻ���", "010-1111-1111");
	LInsert(&list, nameCard);
	
	nameCard = MakeNameCard("�����", "010-2222-2222");
	LInsert(&list, nameCard);
	
	nameCard = MakeNameCard("�ڻ���", "010-3333-3333");
	LInsert(&list, nameCard);
	
	printf("��� ���� ���");
	printf("\n");
	
	if(LFirst(&list, &nameCard)) {
		ShowNameCardInfo(nameCard);
		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		}
	}
	
	printf("\n");
	printf("�ڻ����� ���� ���");
	printf("\n");
	
	if(LFirst(&list, &nameCard)) {
		if(!NameCompare(nameCard, "�ڻ���")) {
			ShowNameCardInfo(nameCard);
		}
		
		while(LNext(&list, &nameCard)) {
			if(!NameCompare(nameCard, "�ڻ���")) {
				ShowNameCardInfo(nameCard);
			}
		}
	}
	
	printf("\n");
	printf("�ڻ����� ���� ����");
	printf("\n");
	
	if(LFirst(&list, &nameCard)) {
		if(!NameCompare(nameCard, "�ڻ���")) {
			ChangePhoneNum(nameCard, "010-9999-9999");
		}
		
		while(LNext(&list, &nameCard)) {
			if(!NameCompare(nameCard, "�ڻ���")) {
				ChangePhoneNum(nameCard, "010-9999-9999");
			}
		}
	}
	
	printf("\n");
	printf("��� ���� ���");
	printf("\n");
	
	if(LFirst(&list, &nameCard)) {
		ShowNameCardInfo(nameCard);
		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		}
	}
	
	printf("\n");
	printf("�ڻ����� ���� ����");
	printf("\n");
	
	if(LFirst(&list, &nameCard)) {
		if(!NameCompare(nameCard, "�ڻ���")) {
			LRemove(&list);
			free(nameCard);
		}
		
		while(LNext(&list, &nameCard)) {
			if(!NameCompare(nameCard, "�ڻ���")) {
				LRemove(&list);
				free(nameCard);
			}
		}
	}
	
	printf("\n");
	printf("��� ���� ���");
	printf("\n");
	
	if(LFirst(&list, &nameCard)) {
		ShowNameCardInfo(nameCard);
		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		}
	}
	
	printf("\n");
	
	printf("���� �������� ��: %d\n", LCount(&list));
	
	return 0;
}
