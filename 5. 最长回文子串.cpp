// 给你一个字符串 s，找到 s 中最长的 回文子串
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int l = 0, r = 0;
        int len = s.size();
        vector<vector<bool>> v(len, vector<bool>(len));
        // 动态规划：v[i][j] = true->从i到j的子串是回文
        for (int i = 0; i < len; i++) // 初始化
            v[i][i] = true;
        for (int sl = 2; sl <= len; sl++) // 逐渐增长子串长度
        {
            for (int i = 0; i <= len - sl; i++) // i从前往后移动
            {
                if (s[i] == s[i + sl - 1]) // 字符匹配
                {
                    if (i + 1 == i + sl - 1) // 如果i和j相邻则直接是回文
                        v[i][i + sl - 1] = true;
                    else if (v[i + 1][i + sl - 1 - 1]) // i和j不相邻，判断i+1到j-1是否是回文
                        v[i][i + sl - 1] = true;
                }
            }
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (v[i][j] && (r - l + 1 < j - i + 1)) // 找最长回文子串
                    l = i, r = j;
            }
        }
        string ans = s.substr(l, r - l + 1);
        return ans;
    }
};