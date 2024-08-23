// https://leetcode.cn/problems/subarray-sums-divisible-by-k/description/
// 给定一个整数数组 nums 和一个整数 k ，返回其中元素之和可被 k 整除的（连续、非空） 子数组 的数目。
// 子数组 是数组的 连续 部分。
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        int ret = 0;
        int sum = 0;
        hash[0] = 1;
        for (auto i : nums)
        {
            sum += i;
            ret += hash[(sum % k + k) % k];
            hash[(sum % k + k) % k]++;
        }
        return ret;
    }
};