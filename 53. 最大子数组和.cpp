// ����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
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