// ����һ�����շǵݼ�˳�����е��������� nums����һ��Ŀ��ֵ target�������ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ��.
// ��������в�����Ŀ��ֵ target������ [-1, -1]��
// �������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int *ret = (int *)malloc(sizeof(int) * 2);
    ret[0] = -1;
    ret[1] = -1;
    if (numsSize == 0)
        return ret;
    int left = 0;
    int right = numsSize - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    if (nums[left] != target)
        return ret;
    *returnSize = 2;
    ret[0] = left;
    right = numsSize - 1;
    while (left < right)
    {
        int mid = left + (right - left + 1) / 2;
        if (nums[mid] <= target)
            left = mid;
        else
            right = mid - 1;
    }
    ret[1] = right;
    return ret;
}

int main()
{
    int nums[] = {};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 0;
    int retsize = 2;
    int *returnSize = &retsize;
    int *ret = searchRange(nums, numsSize, target, returnSize);
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", ret[i]);
    }
    return 0;
}