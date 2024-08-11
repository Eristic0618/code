// https://leetcode.cn/problems/count-alternating-subarrays/description/
// 给你一个二进制数组nums 。
// 如果一个子数组中 不存在 两个 相邻 元素的值 相同 的情况，我们称这样的子数组为 交替子数组 。
// 返回数组 nums 中交替子数组的数量。
class Solution
{
public:
    long long countAlternatingSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        long long ret = 1, cur = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                cur = 1;
            else
                cur++;
            ret += cur;
        }
        return ret;
    }
};