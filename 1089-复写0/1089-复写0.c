//给你一个长度固定的整数数组 arr ，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。
//注意：请不要在超过该数组长度的位置写入元素。请对输入的数组 就地 进行上述修改，不要从函数返回任何东西
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