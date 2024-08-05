// https://leetcode.cn/problems/house-robber-ii/description/
// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
// 同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
class Solution
{
public:
    int rob1(vector<int> &nums, int begin, int end)
    {
        if (begin > end)
            return 0; // 如果区间不存在返回0
        int n = end - begin + 1;
        vector<int> f(n);
        vector<int> g(n);
        f[0] = nums[begin];
        for (int i = 1; i < n; i++)
        {
            f[i] = g[i - 1] + nums[begin + i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[n - 1], g[n - 1]);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int steal = rob1(nums, 2, n - 2) + nums[0]; // 分类讨论，偷第一间房或者不偷第一间房，把问题变为两个打家劫舍1
        int not_steal = rob1(nums, 1, n - 1);
        return max(steal, not_steal);
    }
};