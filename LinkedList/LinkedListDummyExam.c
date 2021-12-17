#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int data;
	struct _node* next;	
	
} Node;

int main(void){
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;
	
	Node* newNode = NULL;
	int readData;
	//더미를 추가하면 while문 내부에서 head의 자리를 정해줄 필요 없이 미리 확보한다. 
	head = (Node*)malloc(sizeof(Node));
	tail = head;
	
	while (1){
		printf("자연수 입력 : ");
		scanf("%d",&readData);
		if(readData < 1) break;
		
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
		
		tail->next = newNode;
		tail = newNode;
		 
	}
	
	printf("\n\n");
	if (head == tail) {
		printf("저장된 자연수가 없습니다.\n");
	} else {
		cur = head;
		while(cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	
	
	printf("\n\n");
	if (head == tail) {
		printf("저장된 자연수가 없습니다.\n");
	} else {
		Node* delNode = head;
		Node* delNextNode = head->next;
		
		while(delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			
			printf("%d를 삭제합니다.\n", delNode->data);
			free(delNode);
		}
	}
	
	
	
	return 0;
}
