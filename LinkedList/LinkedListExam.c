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
	while (1){
		printf("자연수 입력 : ");
		scanf("%d",&readData);
		if(readData < 1) break;
		
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
		/*
		// 순차적으로 값을 입력해놓고 꼬리에 값을 붙힌다. 
		if(head == NULL) head = newNode; // 첫번째 배열이 비었다면 첫번째 배열에 추가 
		else tail->next = newNode; // 두번째 부터는 next에 저장하기 
		tail = newNode; //현재값을 마지막에 추가
		*/
		
		// 순차적으로 값을 입력하되, 기존의 값을 뒤로 미루고 앞쪽에 값을 넣는다. 
		// tail의 next에 값을 넣는게 아니라, 입력된 값의 next에 움직이는 head를 바라본다. 
		if(head == NULL) tail = newNode;
		else newNode->next = head; // 중요 point 
		head = newNode; //머리값이 이동한다. 
		 
	}
	
	printf("\n\n");
	if (head == NULL) {
		printf("저장된 자연수가 없습니다.\n");
	} else {
		cur = head;
		printf("%d ", cur->data);
		while(cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	
	
	printf("\n\n");
	if (head == NULL) {
		printf("저장된 자연수가 없습니다.\n");
	} else {
		Node* delNode = head;
		Node* delNextNode = head->next;
		printf("%d를 삭제합니다.\n", head->data);
		free(delNode);
		
		while(delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			
			printf("%d를 삭제합니다.\n", delNode->data);
			free(delNode);
		}
	}
	
	
	
	return 0;
}
