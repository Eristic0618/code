// ����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int *nums, int numsSize)
{
    int t = 0;
    int m;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            m = nums[i];
            nums[i] = nums[t];
            nums[t] = m;
            t++;
        }
    }
}

int main()
{
    int nums[5] = {0, 1, 0, 3, 12};
    int numsSize = 5;
    moveZeroes(nums, numsSize);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(nums + i));
    }
    return 0;
}