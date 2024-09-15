// https://leetcode.cn/problems/multiply-strings/description/
//  给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//  注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
class Solution
{
public:
    string add(string num1, string num2)
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

    string mul(vector<int> &A, int b, int k)
    {
        vector<int> C;
        int t = 0;
        for (int i = 0; i < A.size() || t; i++)
        {
            if (i < A.size())
                t += A[i] * b;
            C.push_back(t % 10);
            t /= 10;
        }
        string ans;
        for (int i = C.size() - 1; i >= 0; i--)
        {
            ans += C[i] + '0';
        }
        while (k--)
        {
            ans += '0';
        }
        return ans;
    }

    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        vector<int> v1;
        vector<int> v2;
        for (int i = 0; i < num2.size(); i++)
        {
            v1.push_back(num2[i] - '0');
        }
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            v2.push_back(num1[i] - '0');
        }
        string ans;
        for (int i = 0; i < num2.size(); i++)
        {
            string tmp = mul(v2, v1[i], num2.size() - 1 - i);
            ans = add(ans, tmp);
        }
        return ans;
    }
};