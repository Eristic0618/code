//给定一个含有 n 个正整数的数组和一个正整数 target。
//找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
#include <stdio.h>
#include <stdlib.h>

int minSubArrayLen(int target, int *nums, int numsSize)
{
	int left = 0;
	int right = 0;
	int sum = nums[right];
	if (numsSize == 0 || (right == numsSize - 1 && nums[right] < target))
	{
		return 0;
	}
	if (right == numsSize - 1 && nums[right] >= target)
	{
		return 1;
	}
	while (right < numsSize - 1)
	{
		while (sum < target && left == 0)
		{
			if (right == numsSize - 1 && sum < target)
			{
				return 0;
			}
			right++;
			sum = sum + nums[right];
		}
		if (right < numsSize - 1)
		{
			right++;
			sum = sum + nums[right] - nums[left];
			left++;
		}
		while (sum - nums[left] >= target)
		{
			sum = sum - nums[left];
			left++;
		}
	}
	return right - left + 1;
}

int main()
{
	int nums[] = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
	int target = 15;
	int numsSize = 10;
	int ret = minSubArrayLen(target, nums, numsSize);
	printf("%d", ret);
	return 0;
}