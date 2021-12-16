#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard* MakeNameCard(char* name, char* phone) {
	NameCard* newCard = (NameCard*)malloc(sizeof(NameCard));
	
	strcpy(newCard->name, name);
	strcpy(newCard->phone, phone);
	
	return newCard;
}
void ShowNameCardInfo(NameCard* pcard) {
	printf("  �̸� : %-10s		��ȭ��ȣ : %s\n", pcard->name, pcard->phone);
}
int NameCompare(NameCard* pcard, char* name) {
	return strcmp(pcard->name, name);
	// strcmp�� ���� ���ٸ� 0�� ��ȯ�ȴ�. 
}
void ChangePhoneNumber(NameCard* pcard, char* phone){
	strcpy(pcard->phone, phone);
}

