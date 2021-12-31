#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1; // �ε����� 0���� �����ϹǷ� ������ �ε����� �迭�� ũ�� -1 �Դϴ�.
	int mid;
	
	while(first <= last)
	{
		mid = (first + last) / 2;
		
		if(target == ar[mid])
		{
			return mid;
		}
		else { // ���� ã�� ���ߴٸ� ���� �ٿ����� �����մϴ�. 
			if(target < ar[mid]) // �ٿ��̶�� 
			{
				last = mid - 1; // -1 �� ���� : �ռ� ar[mid]���� target ������ ã�� �������Ƿ� ���� �� ar[mid]�� ������ ���Խ�ų �ʿ䰡 �����ϴ�. 
			} else { // ���̶�� 
				first = mid + 1; // +1 �� ���� : -1 �� ������ �����մϴ�. 
			}
		}
	}
	
	// �ڵ� ��ü�� �����Ϸ��� �ϸ� �Ӹ��� ������ �׸��� ���鼭 ������ �Ϳ� �����ϼ���.
	
	return -1; // ������ Ž�� ���� 
}

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	int idx;
	
	idx = BSearch(arr, sizeof(arr)/sizeof(int), 4);
	
	if(idx == -1)
	{
		printf("Ž�� ���� \n");
	} else {
		printf("Ÿ�� ���� �ε���: %d \n", idx);
	}
	
	return 0;
} 
