// https://leetcode.cn/problems/reverse-words-in-a-string-iii/description/
// ����һ���ַ��� s ������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��
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
