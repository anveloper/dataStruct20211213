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
	// ���� ������ 
	nameCard = MakeNameCard("�׽�Ʈ", "000-1111-0000");
	LInsert(&list, nameCard);
	nameCard = MakeNameCard("��Ʈ��", "000-2222-0000");
	LInsert(&list, nameCard);
	nameCard = MakeNameCard("Ʈ�׽�", "000-3333-0000");
	LInsert(&list, nameCard);
	nameCard = MakeNameCard("ȫ�浿", "000-3536-0000");
	LInsert(&list, nameCard);
	nameCard = MakeNameCard("��λ�", "000-3343-0600");
	LInsert(&list, nameCard);
	nameCard = MakeNameCard("������", "000-3333-0000");
	LInsert(&list, nameCard);
	
	while(1){
		cmdFlag = 0;
		i = 0;
		printf("***** MENU *****\n");
		printf("1. Insert		: �����͸� �߰�\n");
		printf("2. Search		: �����͸� �˻�, �̸��� �������� �˻�\n");
		printf("3. Modify		: �����͸� ����, �̸��� �������� ����\n");
		printf("4. Delete		: �����͸� ����, �̸��� �������� ����\n");
		printf("5. Print All		: ��� �����͸� ���\n");
		printf("6. Count		: ���� �������� ���� ��ȯ\n");
		printf("7. Exit			: �ܼ� ���α׷��� ����\n");
		printf("> Choose the item : ");
		scanf("%d",&cmdFlag); 
		
		if(cmdFlag == 7){
			printf("[ EXIT ]\n");
			break;
		} else if (cmdFlag == 1){ // ������.. �̸��� ������ ��� ������ ������ 
			NameCard newName; 
			printf("[ INSERT ]\n");
			printf("> �̸� : ");
			scanf("%s", &newName.name);
			printf("> ����ó : ");
			scanf("%s", &newName.phone);
			
			nameCard = MakeNameCard(newName.name, newName.phone);
			LInsert(&list, nameCard);
			printf("* %s ����� �Ϸ�Ǿ����ϴ�.\n", newName.name);
			printf("\n");
		} else if (cmdFlag == 2){ // �˻��� ��� ������ (�ذ�) 
			printf("[ SEARCH ]\n");
			printf("> �̸� : ");
			scanf("%s", name);
			i = LCount(&list); //�˻� ���� ���� ��ų �� �� 
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
			if(i == LCount(&list)){  // �˻��� ������ ������ ǥ���ϱ� 
				printf("* �ش��ϴ� �̸��� �����ϴ�.\n");
			} else {
				printf("* %s �˻��� �Ϸ�Ǿ����ϴ�.\n", name);
			} 			
			printf("\n");			
		} else if (cmdFlag == 3){
			printf("[ MODIFY ]\n");
			printf("> �̸� : ");
			scanf("%s", name);
			
			i = LCount(&list); // �̸��� �ִ��� Ȯ���ϴ� �κ� 
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
				printf("* �ش��ϴ� �̸��� �����ϴ�.\n\n");
				continue; 
			} // �̸��� ������ continue 
			
			printf("> ������ ����ó : ");
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
			printf("* %s ������ �Ϸ�Ǿ����ϴ�.\n", name);
		
			printf("\n");	
		} else if (cmdFlag == 4){
			printf("[ DELETE ]\n");
			printf("> �̸� : ");
			scanf("%s", name);
			
			i = LCount(&list); // �̸��� �ִ��� Ȯ���ϴ� �κ� 
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
				printf("* �ش��ϴ� �̸��� �����ϴ�.\n\n");
				continue; 
			} // �̸��� ������ continue 
			
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
			printf("* %s ������ �Ϸ�Ǿ����ϴ�.\n", name);
			
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
			
			printf("���� �������� �� : %d\n", LCount(&list));
			printf("\n");
		} else {
			printf("**** �߸� �Է��Ͽ����ϴ�.****\n");
		}
		while (getchar() != '\n'); 
		//int�� ������ �޾ƾ� �Ҷ�, ���� �� �ٸ� ������ ������ �Ǹ�, ���� ���⿡ �����Ͽ� �������� �Էµ� \n�� �ݺ��ǰ� �ȴ�. 
	}
	
	return 0;
}
/*
int main(void){
	List list;
	NameCard comNameCard;
	NameCard* nameCard;
	ListInit(&list);
	
	nameCard = MakeNameCard("�ֻ���", "010-1111-1111");
	LInsert(&list, nameCard);
	
	nameCard = MakeNameCard("�����", "010-2222-2222");
	LInsert(&list, nameCard);
	
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
	
	// �ڻ����� ���� ���� 
	printf("== �ڻ����� ������ ���� ==\n"); 
	if(LFirst(&list,&nameCard)) {
		if(NameCompare(nameCard,"�ڻ���") == 0) {
			ChangePhoneNumber(nameCard, "010-9999-9999");		
		}
		while(LNext(&list, &nameCard)) {
			if(NameCompare(nameCard,"�ڻ���") == 0) {
				ChangePhoneNumber(nameCard, "010-9999-9999");		
			}
		} 
	} 
	
	// ��� ���� ���
	printf("== ��� ����� ���� ��� ==\n"); 
	if(LFirst(&list,&nameCard)) {
		ShowNameCardInfo(nameCard);		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		} 
	} 
	
	// �ڻ����� ���� ���� 
	if(LFirst(&list,&nameCard)) {
		if(NameCompare(nameCard,"�ڻ���") == 0) {
			LRemove(&list);
			free(nameCard);		
		}
		while(LNext(&list, &nameCard)) {
			if(NameCompare(nameCard,"�ڻ���") == 0) {
				LRemove(&list);		
				free(nameCard);	
			}
		} 
	} 
	
	// ��� ���� ���
	printf("== ��� ����� ���� ��� ==\n"); 
	if(LFirst(&list,&nameCard)) {
		ShowNameCardInfo(nameCard);		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		} 
	} 
	printf("���� �������� �� : %d\n",LCount(&list));
	
	return 0;
}
*/
