// �Ʒ� �ڵ� ��ü�� �ڵ� ���� 
#include <stdio.h>

int sum = 25; // ������ ���� 

void add(int num) // ���� ���� 
{
	num += 10;
	printf("add �Լ�: %d \n", num);
	sum += num;
}

int main(void) // ���� ���� 
{
	int num = 10;
	add(num);
	printf("main �Լ�: %d \n", num);
	printf("���� ���� sum: %d \n", sum); // � �Լ� �ȿ����� ���� ���� 

	return 0;
}
