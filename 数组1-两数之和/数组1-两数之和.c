//����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
//����԰�����˳�򷵻ش𰸡�
#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *p1, const void *p2)
{
	return ((int *)p1)[0] - ((int *)p2)[0];
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int n = numsSize;
	int arr[n][2];
	for (int i = 0; i < numsSize; i++)
	{
		arr[i][0] = nums[i];
		arr[i][1] = i;
	}
	qsort(arr, n, sizeof(int(*)[2]), cmp_int);
	for (int i = 0; i < n; i++)
	{
		int left = 0;
		int right = n - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (arr[mid][0] == target - nums[i] && arr[mid][1] != i)
			{
				*returnSize = 2;
				int *ret = (int *)malloc(sizeof(int) * 2);
				ret[0] = i;
				ret[1] = arr[mid][1];
				return ret;
			}
			else if (arr[mid][0] > target - nums[i])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
	}
	*returnSize = 0;
	return NULL;
}

int main()
{
	int nums[] = {3, 2, 4};
	int target = 6;
	int numsSize = 3;
	int ret = 0;
	int *returnSize = &ret;
	int *ret1 = twoSum(nums, numsSize, target, returnSize);
	for (int i = 0; i < 2; i++)
	{
		printf("%d ", ret1[i]);
	}
	return 0;
}