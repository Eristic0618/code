//����һ�����ȹ̶����������� arr �����㽫�������г��ֵ�ÿ���㶼��дһ�飬���������Ԫ������ƽ�ơ�
//ע�⣺�벻Ҫ�ڳ��������鳤�ȵ�λ��д��Ԫ�ء������������� �͵� ���������޸ģ���Ҫ�Ӻ��������κζ���
#include <stdio.h>
#include <stdlib.h>

void duplicateZeros(int *arr, int arrSize)
{
	int cur = 0;
	int dest = -1;
	int n = arrSize;
	while (cur <= n - 1)
	{
		if (arr[cur])
		{
			dest++;
		}
		else
		{
			dest += 2;
		}
		if (dest >= n - 1)
		{
			break;
		}
		cur++;
	}
	if (dest == n)
	{
		arr[n - 1] = 0;
		cur--;
		dest -= 2;
	}
	while (cur >= 0)
	{
		if (arr[cur])
		{
			arr[dest--] = arr[cur--];
		}
		else
		{
			arr[dest--] = 0;
			arr[dest--] = 0;
			cur--;
		}
	}
}

int main()
{
	int arr[100] = {1, 0, 2, 3, 0, 4, 5, 0};
	int arrSize = 7;
	duplicateZeros(arr, arrSize);
	for (int i = 0; i < arrSize; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}