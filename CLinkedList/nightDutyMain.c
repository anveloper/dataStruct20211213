#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

Employee* WhosNightDuty(List* plist, char* name, int day);
void ShowEmployeeInfo(Employee* emp);

int main(void){
	Employee* pemp;
	List list;
	ListInit(&list);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 1;
	strcpy(pemp->name, "Terry");
	LInsert(&list, pemp);
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 2;
	strcpy(pemp->name, "Jerry");
	LInsert(&list, pemp);
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 3;
	strcpy(pemp->name, "Harry");
	LInsert(&list, pemp);
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 4;
	strcpy(pemp->name, "Merly");
	LInsert(&list, pemp);
	
	printf("Terry +1 ~ +4\n");
	
	pemp = WhosNightDuty(&list, "Terry", 1);
	ShowEmployeeInfo(pemp);
	
	pemp = WhosNightDuty(&list, "Terry", 2);
	ShowEmployeeInfo(pemp);
	
	pemp = WhosNightDuty(&list, "Terry", 3);
	ShowEmployeeInfo(pemp);
	
	pemp = WhosNightDuty(&list, "Terry", 4);
	ShowEmployeeInfo(pemp);
	
	printf("Every +1\n");
	
	pemp = WhosNightDuty(&list, "Terry", 1);
	ShowEmployeeInfo(pemp);
	
	pemp = WhosNightDuty(&list, "Jerry", 1);
	ShowEmployeeInfo(pemp);
	
	pemp = WhosNightDuty(&list, "Harry", 1);
	ShowEmployeeInfo(pemp);
	
	pemp = WhosNightDuty(&list, "Merly", 1);
	ShowEmployeeInfo(pemp);
	
	return 0;
}
Employee* WhosNightDuty(List* plist, char* name, int day) {
	Employee* ret = NULL;
	int size = LCount(plist);
	if(LFirst(plist, &ret) && !strcmp(ret->name, name)){
		while (LNext(plist, &ret) && !strcmp(ret->name, name)) {
		}
		LNext(plist, &ret);
	}
	// Terry��� �����ڰ� ������ �ǵ��� ã�´�. (�ذ�)
	// Terry���� �ٸ� �����ڸ� �������� ������ ���Ѵ�. ���߿� ��������.. 
	
	while(LNext(plist, &ret) && day >= 0) day--;
		
	return ret;
	
}


void ShowEmployeeInfo(Employee* emp) {
	printf("Employee Name	: %s\n", emp->name);
	printf("Employee Number : %d\n", emp->empNum);
}
