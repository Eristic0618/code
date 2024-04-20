// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
// ����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� ����˳�� ���ء�
// �������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
class Solution
{
    vector<string> letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    void _letterCombinations(string &digits, vector<string> &ret, string tmp, size_t pile)
    {
        if (pile == digits.size())
        {
            ret.push_back(tmp);
            return;
        }
        int n = digits[pile] - '0';
        string str = letter[n];
        for (auto ch : str)
        {
            _letterCombinations(digits, ret, tmp + ch, pile + 1);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ret;
        if (digits.size() == 0)
        {
            return ret;
        }
        _letterCombinations(digits, ret, "", 0);
        return ret;
    }
};
