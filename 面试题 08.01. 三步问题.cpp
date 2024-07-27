// https://leetcode.cn/problems/three-steps-problem-lcci/description/
// �������⡣�и�С��������¥�ݣ�¥����n��̨�ף�С��һ�ο�����1�ס�2�׻�3�ס�ʵ��һ�ַ���������С���ж�������¥�ݵķ�ʽ��������ܴܺ�����Ҫ�Խ��ģ1000000007��
class Solution
{
public:
    int waysToStep(int n)
    {
        vector<long long> dp(n + 4, 0); // ��n�࿪4���ռ䣬һ�������±��̨������Ӧ��һ�����ֹn<3����Խ��
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