// https://leetcode.cn/problems/reverse-only-letters/description/
// 给你一个字符串 s ，根据下述规则反转字符串：
// 所有非英文字母保留在原有位置。
// 所有英文字母（小写或大写）位置反转。
// 返回反转后的 s 。
class Solution
{
public:
    bool isletter(char &ch)
    {
        if (ch >= 'A' && ch <= 'Z')
            return true;
        if (ch >= 'a' && ch <= 'z')
            return true;
        else
            return false;
    }

    string reverseOnlyLetters(string s)
    {
        int begin = 0, end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !isletter(s[begin]))
                ++begin;
            while (begin < end && !isletter(s[end]))
                --end;
            swap(s[begin], s[end]);
            ++begin;
            --end;
        }
        return s;
    }
};