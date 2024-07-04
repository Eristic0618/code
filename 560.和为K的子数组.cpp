// https://leetcode.cn/problems/subarray-sum-equals-k/description/
// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
// 子数组是数组中元素的连续非空序列

// 前缀和+哈希表
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        int count = 0;
        int sum = 0;
        hash[0] = 1;
        for (auto i : nums)
        {
            sum += i;
            count += hash[sum - k];
            hash[sum]++;
        }
        return count;
    }
};