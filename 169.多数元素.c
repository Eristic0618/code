// https://leetcode.cn/problems/majority-element/description/
// 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ? n/2 ? 的元素。
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
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