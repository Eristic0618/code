// https://leetcode.cn/problems/first-unique-character-in-a-string/description/
// 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int count[26] = {0};
        for (auto ch : s)
        {
            count[ch - 'a']++;
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (count[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};