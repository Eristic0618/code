// https://leetcode.cn/problems/single-number-ii/description/
// 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
// 你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
            hash[nums[i]]++;
        int ans;
        for (auto &[key, value] : hash)
        {
            if (value == 1)
                ans = key;
        }
        return ans;
    }
};