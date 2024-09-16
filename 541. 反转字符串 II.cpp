// https://leetcode.cn/problems/reverse-string-ii/description/
//  ����һ���ַ��� s ��һ������ k�����ַ�����ͷ����ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ���
//  ���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
//  ���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
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