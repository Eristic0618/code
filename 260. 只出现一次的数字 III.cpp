// https://leetcode.cn/problems/single-number-iii/description/
//  给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
//  你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        if (nums.size() == 2)
            return nums;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
            hash[nums[i]]++;
        vector<int> ans;
        for (auto &[key, value] : hash)
        {
            if (value == 1)
                ans.push_back(key);
        }
        return ans;
    }
};