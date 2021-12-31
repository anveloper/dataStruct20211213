#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1; // �ε����� 0���� �����ϹǷ� ������ �ε����� �迭�� ũ�� -1 �Դϴ�.
	int mid;
	int opCnt = 0; // �� ������ Ƚ���� ����մϴ�. 
	
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
		
		opCnt++; // ���� 1ȸ�� �� ���� �� 1 �߰� 
	}
	
	printf("�񱳿���Ƚ��: %d \n", opCnt);
	
	return -1; // ������ Ž�� ���� 
}

int main(void)
{
	int arr1[500] = {0,}; // �迭�� ��� ��Ұ� 0���� �ʱ�ȭ�˴ϴ�. ���� Ž���� ��� -1�� ã�� �� 500�� ã���ϴ�. 
	int arr2[5000] = {0,}; // �迭�� ��� ��Ұ� 0���� �ʱ�ȭ�˴ϴ�. ���� Ž���� ��� -1�� ã�� �� 5000�� ã���ϴ�. 
	int arr3[50000] = {0,}; // �迭�� ��� ��Ұ� 0���� �ʱ�ȭ�˴ϴ�. ���� Ž���� ��� -1�� ã�� �� 50000�� ã���ϴ�. 
	int idx;
	
	idx = BSearch(arr3, sizeof(arr3)/sizeof(int), -1); // ���� ���� ã�� ������ �־��� ��츦 Ȯ���� �� �־�Դϴ�.
	
	if(idx == -1)
	{
		printf("Ž�� ���� \n");
	} else {
		printf("Ÿ�� ���� �ε���: %d \n", idx);
	}
	
	return 0;
} 
