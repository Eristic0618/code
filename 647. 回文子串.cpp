// 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
// 回文字符串 是正着读和倒过来读一样的字符串。
// 子字符串 是字符串中的由连续字符组成的一个序列。
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int ret = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (i == j || i + 1 == j)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                    if (dp[i][j] == 1)
                    {
                        ret++;
                    }
                }
            }
        }
        return ret;
    }
};