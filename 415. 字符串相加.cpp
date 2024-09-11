// https://leetcode.cn/problems/add-strings/description/
// ���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺͲ�ͬ�����ַ�����ʽ���ء�
// �㲻��ʹ���κ΃Ƚ������ڴ���������Ŀ⣨���� BigInteger���� Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��
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