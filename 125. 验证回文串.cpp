// https://leetcode.cn/problems/valid-palindrome/description/
//  ����ڽ����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮�󣬶������Ŷ��ͷ��Ŷ���һ�����������Ϊ�ö�����һ�� ���Ĵ� ��
//  ��ĸ�����ֶ�������ĸ�����ַ���
//  ����һ���ַ��� s��������� ���Ĵ� ������ true �����򣬷��� false ��
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str;
        for (int i = 0; i < s.size(); i++)
        {
            if (isupper(s[i]))
                str += s[i] - 'A' + 'a';
            else if (islower(s[i]) || isdigit(s[i]))
                str += s[i];
            else
                continue;
        }
        if (str.empty())
            return true;
        int l = 0, r = str.size() - 1;
        while (l < r)
        {
            if (str[l] != str[r])
                return false;
            l++, r--;
        }
        return true;
    }
};
