#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

int main(void) {
	List list;
	ListInit(&list);
	int data;
	
	LInsert(&list, 8);	
	LInsert(&list, 7);	
	LInsert(&list, 6);	
	LInsert(&list, 5);	
	LInsert(&list, 4);	
	LInsert(&list, 3);	
	LInsert(&list, 2);	
	LInsert(&list, 1);
	
	if(LFirst(&list, &data)) {
		printf("%d ",data);
		while(LNext(&list,&data)){
			printf("%d ",data);	
		}
	}
	printf("\n\n");
	int n = 0;
	if(LFirst(&list, &data)) {
		printf("%d ",data);
		while(LNext(&list,&data)){
			if(n == 4) break;
			printf("%d ",data);	
			n++;
		}
		
		while(LPrevious(&list,&data)){
			if(n == 3) break;
			printf("%d ",data);	
			n--;
		}
		
		while(LNext(&list,&data)){
			if(n == 7) break;
			printf("%d ",data);	
			n++;
		}
		
	}
	
	
	return 0;
}
