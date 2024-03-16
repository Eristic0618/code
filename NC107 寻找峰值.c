// https://www.nowcoder.com/share/jump/8993698061708605588253
// 给定一个长度为n的数组nums，请你找到峰值并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个所在位置即可。
// 1.峰值元素是指其值严格大于左右相邻值的元素。严格大于即不能有等于
// 2.假设 nums[-1] = nums[n] = ?∞
// 3.对于所有有效的 i 都有 nums[i] != nums[i + 1]
// 4.你可以使用O(logN)的时间复杂度实现此问题吗
int findPeakElement(int *nums, int numsLen)
{
    if (numsLen == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    else if (nums[numsLen - 2] < nums[numsLen - 1])
        return numsLen - 1;
    int left = 0, mid = 1, right = 2;
    while (right < numsLen)
    {
        if (nums[mid] > nums[left] && nums[mid] > nums[right])
            return mid;
        else
        {
            left++;
            mid++;
            right++;
        }
    }
    return -1;
}