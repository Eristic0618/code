// https://leetcode.cn/problems/max-consecutive-ones/description/
// 给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
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