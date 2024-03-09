// https://leetcode.cn/problems/max-consecutive-ones/description/
// ����һ������������ nums �� ��������������� 1 �ĸ�����
int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int prev = 0, cur = 0;
    int maxlen = 0;
    while (cur < numsSize)
    {
        if (nums[prev] == 1 && nums[cur] == 1)
            cur++;
        else if (nums[prev] != nums[cur])
        {
            if (maxlen < (cur - prev))
                maxlen = cur - prev;
            prev = cur;
        }
        else if (nums[prev] == 0 && nums[cur] == 0)
        {
            prev++;
            cur++;
        }
    }
    if (nums[cur - 1] != 0)
    {
        if (maxlen < (cur - prev))
            maxlen = cur - prev;
    }
    return maxlen;
}