#include <stdio.h>

struct employee
{
	char name[20];
	char pid[20];
	int salary;
};

int main(void)
{
	struct employee emp[3];
	int i;
	
	for(i=0; i<3; i++)
	{
		printf("������ �̸�: ");
		scanf("%s", emp[i].name);
		
		printf("�ֹε�Ϲ�ȣ: ");
		scanf("%s", emp[i].pid);
		
		printf("�޿� ����: ");
		scanf("%d", &emp[i].salary);
	}
	
	for(i=0; i<3; i++)
	{
		printf("������ �̸�: %s \n", emp[i].name);
		printf("�ֹε�Ϲ�ȣ: %s \n", emp[i].pid);
		printf("�޿� ����: %d \n", emp[i].salary);
	}
	
	return 0;
}
