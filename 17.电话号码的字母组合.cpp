// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
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
