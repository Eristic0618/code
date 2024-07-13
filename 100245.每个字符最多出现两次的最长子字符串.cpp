// https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/description/
// 给你一个字符串 s ，请找出满足每个字符最多出现两次的最长子字符串，并返回该子字符串的 最大 长度。
class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        vector<int> hash(26);
        int prev = 0, cur = 0;
        int ret = 1;
        while (cur < s.size())
        {
            hash[s[cur] - 'a']++;
            if (hash[s[cur] - 'a'] == 3)
            {
                while (s[prev] != s[cur])
                {
                    hash[s[prev] - 'a']--;
                    prev++;
                }
                hash[s[prev] - 'a']--;
                prev++;
            }
            ret = max(ret, cur - prev + 1);
            cur++;
        }
        return ret;
    }
};