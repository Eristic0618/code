// https://leetcode.cn/problems/target-sum/description/
// ����һ���Ǹ��������� nums ��һ������ target ��
// �������е�ÿ������ǰ��� '+' �� '-' ��Ȼ�������������������Թ���һ�� ���ʽ ��
// ���磬nums = [2, 1] �������� 2 ֮ǰ��� '+' ���� 1 ֮ǰ��� '-' ��Ȼ���������õ����ʽ "+2-1" ��
// ���ؿ���ͨ��������������ġ����������� target �Ĳ�ͬ ���ʽ ����Ŀ��

// ˼·��
// ����������Ϊ���������֣���������ֵľ���ֵ֮��a��b
// a - b = target��a + b = �����sum -> 2a = sum + target -> a = (sum + target) / 2
// Ȼ��Ϳ���ת��Ϊ01�������⣬�ҳ��ж�����ѡ�����Ըպõ���a
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int _target)
    {
        int sum = 0;
        for (auto i : nums)
            sum += i;
        int a = (sum + _target) / 2;
        if (a < 0 || (sum + _target) % 2 == 1)
            return 0;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(a + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= a; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1])
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        return dp[n][a];
    }
};

// ���������Ż�
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int _target) {
//         int sum = 0;
//         for(auto i : nums)
//             sum += i;
//         int a = (sum + _target) / 2;
//         if(a < 0 || (sum + _target) % 2 == 1)
//             return 0;
//         int n = nums.size();
//         vector<int> dp(a + 1);
//         dp[0] = 1;
//         for(int i = 1;i <= n;i++)
//             for(int j = a;j >= nums[i-1];j--)
//             {
//                 dp[j] += dp[j-nums[i-1]];
//             }
//         return dp[a];
//     }
// };