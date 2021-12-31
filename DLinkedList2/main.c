#include <stdio.h>
#include "DLinkedList.h"

int main(void) {
	List list;
	LData data;
	ListInit(&list);
	
	while(1) {
		printf("�ڿ��� �Է�: ");
		scanf("%d", &data);
		
		if(data < 1) {
			break;
		}
		
		LInsert(&list, data);
	}
	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	
	return 0;
}
