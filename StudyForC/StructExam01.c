#include <stdio.h>

struct employee
{
	char name[20];
	char pid[20];
	int salary;
};

int main(void)
{
	struct employee emp;
	
	printf("������ �̸�: ");
	scanf("%s", emp.name);
	
	printf("�ֹε�Ϲ�ȣ: ");
	scanf("%s", emp.pid);

	printf("�޿� ����: ");
	scanf("%d", &emp.salary);
	
	printf("\n");
	
	printf("������ �̸�: %s \n", emp.name);
	printf("�ֹε�Ϲ�ȣ: %s \n", emp.pid);
	printf("�޿� ����: %d \n", emp.salary);
	
	printf("\n");
	
	return 0;
}
