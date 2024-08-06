// https://leetcode.cn/problems/delete-and-earn/description/
// 给你一个整数数组 nums ，你可以对它进行一些操作。
// 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
// 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        const int N = 10001;
        int n = nums.size();
        vector<int> sum(N);
        for (auto i : nums)
            sum[i] += i;
        vector<int> f(N);
        auto g = f;
        f[0] = sum[0];
        for (int i = 1; i < N; i++)
        {
            f[i] = g[i - 1] + sum[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[N - 1], g[N - 1]);
    }
};