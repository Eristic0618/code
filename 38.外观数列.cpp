// https://leetcode.cn/problems/count-and-say/description/
// 给定一个正整数 n ，输出外观数列的第 n 项。
// 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。
// 你可以将其视作是由递归公式定义的数字字符串序列：
// countAndSay(1) = "1"
// countAndSay(n) 是对 countAndSay(n-1) 的描述，然后转换成另一个数字字符串。
// 前五项如下：
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 第一项是数字 1
// 描述前一项，这个数是 1 即 “ 一 个 1 ”，记作 "11"
// 描述前一项，这个数是 11 即 “ 二 个 1 ” ，记作 "21"
// 描述前一项，这个数是 21 即 “ 一 个 2 + 一 个 1 ” ，记作 "1211"
// 描述前一项，这个数是 1211 即 “ 一 个 1 + 一 个 2 + 二 个 1 ” ，记作 "111221"
class Solution
{
public:
    string countAndSay(int n)
    {
        vector<int> num = {1};
        string ret;
        for (int i = 1; i < n; ++i)
        {
            int left = 0, right = 0;
            vector<int> tmp;
            int count = 0;
            while (right < num.size())
            {
                count = 0;
                while (right < num.size() && num[left] == num[right])
                    right++;
                count = right - left;
                tmp.push_back(count);
                tmp.push_back(num[left]);
                left = right;
            }
            num = tmp;
        }
        for (auto i : num)
        {
            ret += i + '0';
        }
        return ret;
    }
};