// https://leetcode.cn/problems/three-steps-problem-lcci/description/
// 三步问题。有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶或3阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模1000000007。
class Solution
{
public:
    int waysToStep(int n)
    {
        vector<long long> dp(n + 4, 0); // 比n多开4个空间，一方面让下标和台阶数对应，一方面防止n<3导致越界
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        if (n <= 3)
            return dp[n];
        for (int k = 4; k <= n; k++)
        {
            dp[k] = (dp[k - 1] + dp[k - 2] + dp[k - 3]) % 1000000007;
        }
        return dp[n];
    }
};