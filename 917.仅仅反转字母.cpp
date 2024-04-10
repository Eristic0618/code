// https://leetcode.cn/problems/reverse-only-letters/description/
// ����һ���ַ��� s ��������������ת�ַ�����
// ���з�Ӣ����ĸ������ԭ��λ�á�
// ����Ӣ����ĸ��Сд���д��λ�÷�ת��
// ���ط�ת��� s ��
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