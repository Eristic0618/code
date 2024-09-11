// https://leetcode.cn/problems/add-strings/description/
// 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
// 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        vector<int> tmp;
        int flag = 0;
        vector<int> A, B;
        for (int i = num1.size() - 1; i >= 0; i--)
            A.push_back(num1[i] - '0');
        for (int i = num2.size() - 1; i >= 0; i--)
            B.push_back(num2[i] - '0');
        for (int i = 0; i < A.size() || i < B.size(); i++)
        {
            int bit = 0;
            if (i < A.size())
                bit += A[i];
            if (i < B.size())
                bit += B[i];
            bit += flag;
            flag = 0;
            if (bit > 9)
            {
                flag = 1;
                bit %= 10;
            }
            tmp.push_back(bit);
        }
        if (flag == 1)
            tmp.push_back(1);
        string str;
        for (int i = tmp.size() - 1; i >= 0; i--)
            str += tmp[i] + '0';
        return str;
    }
};