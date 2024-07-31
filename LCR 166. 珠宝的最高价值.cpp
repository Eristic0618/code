// https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/description/
// 现有一个记作二维矩阵 frame 的珠宝架，其中 frame[i][j] 为该位置珠宝的价值。拿取珠宝的规则为：
// 只能从架子的左上角开始拿珠宝
// 每次可以移动到右侧或下侧的相邻位置
// 到达珠宝架子的右下角时，停止拿取
// 注意：珠宝的价值都是大于 0 的。除非这个架子上没有任何珠宝，比如 frame = [[0]]。
class Solution
{
public:
    int jewelleryValue(vector<vector<int>> &frame)
    {
        int m = frame.size();
        int n = frame[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i - 1][j - 1];
        return dp[m][n];
    }
};