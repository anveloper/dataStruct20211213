#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int * ptr = (int*)malloc(sizeof(int)*10);
	// malloc ���� �Ҵ�� �޸𸮴� �迭�� ���� �����մϴ�. 
	// ptr[i] => *(ptr+i) �ε� ���� �����մϴ�.
	// ptr[i]�� ���̹Ƿ� scanf�� �� �ּҰ��� &ptr[i]�� �����ؾ� �մϴ�. 
	
	for(i=0; i<10; i++)
	{
		scanf("%d", &ptr[i]);
	}
	
	for(i=0; i<10; i++)
	{
		printf("%d ", *(ptr+i));
	}
	
	free(ptr);
	
	return 0;
}
