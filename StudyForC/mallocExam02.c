#include <stdio.h>
#include <stdlib.h>

typedef struct _person
{
	char name[20];
	int age;
} Person;

int main(void)
{ 
	int i;
	int number;

	printf("����� ���ڸ� �Է����ּ���: ");
	scanf("%d", &number);
	
	Person * person = (Person*)malloc(sizeof(Person) * number);
	// �������� �迭�� �ƴ�(�ּ� ������ �����ϴ� �迭�� �ƴ�) 
	// ����ü �迭�� ù��° ���� ���� ����ü �������ϻ�
	// ���� �ٷ� ������ ���� ���� 
	
	for(i = 0; i<number; i++)
	{
		printf("%d��° ����� �̸��� �Է����ּ���: ", i+1);
		scanf("%s", person[i].name); // �迭�� �̸��� �ּҰ�
		
		printf("%d��° ����� ���̸� �Է����ּ���: ", i+1);
		scanf("%d", &person[i].age);
	}
	
	for(i = 0; i<number; i++)
	{
		printf("%d��° ����� �̸�, ����: %s, %d�� \n", i+1, person[i].name, person[i].age);
	}
	
	free(person);
	
	return 0;
}
