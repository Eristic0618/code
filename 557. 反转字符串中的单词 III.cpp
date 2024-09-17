// https://leetcode.cn/problems/reverse-words-in-a-string-iii/description/
// 给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
class Solution
{
public:
    void reverse(string &s, int l, int r)
    {
        while (l < r)
            swap(s[l++], s[r--]);
    }

    string reverseWords(string s)
    {
        int l = 0, r = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            if (i < s.size() && s[i] != ' ')
                r++;
            if (i == s.size() || s[i] == ' ')
            {
                reverse(s, l, r - 1);
                r++;
                l = r;
            }
        }
        return s;
    }
};
