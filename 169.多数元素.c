// https://leetcode.cn/problems/majority-element/description/
// ����һ����СΪ n ������ nums ���������еĶ���Ԫ�ء�����Ԫ����ָ�������г��ִ��� ���� ? n/2 ? ��Ԫ�ء�
// ����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ�ء�
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int majorityElement(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int prev = 0, cur = 0;
    while (cur < numsSize)
    {
        if (cur < numsSize && nums[prev] == nums[cur])
        {
            cur++;
        }
        if (cur - prev > (numsSize / 2))
            return nums[prev];
        if (cur < numsSize && nums[prev] != nums[cur])
        {
            prev++;
        }
    }
    return -1;
}