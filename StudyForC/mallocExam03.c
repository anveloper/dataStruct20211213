/*
����ü�� ����� Person ȸ���� �Է¹޽��ϴ�.
���α׷� ���� �� �Է��� ��� ���� �� ������ 0�� �Է¹����� �Է� �ޱ⸦ �ߴ��ϰ� �Է¹��� ��� �����͸� ����մϴ�.
����� �� ��� �������� �޸𸮸� �ݳ��մϴ�. 

[ ���α׷� ���� ]
ȸ���� �߰��Ͻðڽ��ϱ�?: 1 [����] 
1��° ȸ���� �̸��� �Է����ּ���. : aa [����]
1��° ȸ���� ���̸� �Է����ּ���. : 11 [����]
ȸ���� �߰��Ͻðڽ��ϱ�?: 1 [����]  
2��° ȸ���� �̸��� �Է����ּ���. : bb [����]
2��° ȸ���� ���̸� �Է����ּ���. : 22 [����] 
ȸ���� �߰��Ͻðڽ��ϱ�?: 0 [����] 

== ��ü ȸ�� ����Ʈ ==
1��° ȸ�� : aa, 11��
2��° ȸ�� : bb, 22��

== �޸� �ݳ� ==
1��° ����� �޸𸮸� �ݳ��մϴ�.
2��° ����� �޸𸮸� �ݳ��մϴ�.
�����ϴ� �޸𸮰� �����ϴ�. 

[ ��Ʈ ]
����ü�� 3�� �����ؾ� �մϴ�.
Person * current = NULL;
Person * first = NULL;
Person * last = NULL;

ó�� ����� �ι�° ����� ��ġ�� �˾ƾ� �մϴ�.
�ι�° ����� ����°����� ��ġ�� �˾ƾ� �մϴ�.
������ ����� next �������� NULL�� ���� �մϴ�.
ó������� ��ġ�� �־��� ��Ȳ���� �ݺ����� ����, ������ ������� �����Ͽ��ּ���.
first �������� ó������� ��ġ�� ���� �մϴ�.
current �������� ���� �� �¾(malloc���� �������) ����� ��ġ�� ���ų�, �ݺ������� ������ ������� ������ �� ���˴ϴ�.
last �������� ���� �������� �߰���(�������, malloc���� ������) ����� �ּҰ� ���� �մϴ�.
last�������� ȸ���� �߰��� �� ����(�� ���ο� ����� �߰��� �� ����) ���� �ٲ��� �մϴ�.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _person
{
	char name[20];
	int age;
	struct _person * next;
} Person;

int main(void)
{
	
	int input = 1;
	int i = 0;
	
	Person * current = NULL;
	Person * first = NULL;
	Person * last = NULL;
	
	while(1) {
		printf("ȸ���� �߰��Ͻðڽ��ϱ�?: ");
		scanf("%d", &input);
		
		if(input == 0)
		{
			break;
		}
		
		Person * current = (Person*)malloc(sizeof(Person)); // ����ü ������ ����
		// �ּұ� ������ ���� �����ؾ� �մϴ�. 
		
		printf("%d�� ȸ���� �̸��� �Է����ּ���.: ", i + 1);
		scanf("%s", (*current).name);
		
		printf("%d�� ȸ���� ���̸� �Է����ּ���.: ", i + 1);
		scanf("%d", &(*current).age);
		
		current->next = NULL;
		
		if(first == NULL)
		{
			first = current;
		} else {
			last->next = current; 
		}
		
		last = current; // ù��° ���ට last�� current�� �����ϴ�. �ּҰ��� �����Ƿ� 
		i++;
	}
	
	i = 0;
	
	printf("== ��ü ȸ�� ����Ʈ ==\n");
	current = first;
	
	while(1)
	{
		printf("%d��° ȸ�� : %s, %d��\n", i + 1, current->name, current->age);
		
		if(current->next == NULL)
		{
			break;
		}
	
		current = current->next;
		i++;
	}
	
	i = 0;
	
	printf("== �޸� �ݳ� ==\n");
	current = first;
	
	while(1)
	{
		 
		printf("%d�� ����� �޸𸮸� �ݳ��մϴ�.\n", i+1);
		free(current);
		
		if(current->next == NULL)
		{
			printf("�����ϴ� �޸𸮰� �����ϴ�. \n");
			break;
		}

		current = current->next;
		i++;
	}
	
	return 0;
}
