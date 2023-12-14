// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1);
        int ret = INT_MIN;
        for (int i = 1; i < n + 1; i++)
        {
            dp[i] = max(nums[i - 1] + dp[i - 1], nums[i - 1]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};