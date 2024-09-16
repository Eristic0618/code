// https://leetcode.cn/problems/reverse-string-ii/description/
//  给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
//  如果剩余字符少于 k 个，则将剩余字符全部反转。
//  如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
class Solution
{
public:
    void reverse(string &s, int l, int r)
    {
        while (l < r)
            swap(s[l++], s[r--]);
    }

    string reverseStr(string s, int k)
    {
        int l = 0, r = 2 * k - 1;
        while (r < s.size())
        {
            reverse(s, l, (l + r) / 2);
            l = r + 1;
            r += 2 * k;
        }
        if (l < s.size() && (l + r) / 2 > s.size() - 1)
            reverse(s, l, s.size() - 1);
        else if (l < s.size() && (l + r) / 2 <= s.size() - 1)
            reverse(s, l, (l + r) / 2);
        return s;
    }
};