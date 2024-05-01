// https://leetcode.cn/problems/zigzag-conversion/description/
// ��һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ��� Z �������С�
// ���������ַ���Ϊ "PAYPALISHIRING" ����Ϊ 3 ʱ���������£�
// P   A   H   N
// A P L S I I G
// Y   I   R
// ֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"PAHNAPLSIIGYIR"��
// ����ʵ��������ַ�������ָ�������任�ĺ���
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string ret;
        int d = 2 * numRows - 2;
        int n = s.size();
        for (int i = 0; i < n; i += d)
        {
            ret += s[i];
        }
        for (int k = 1; k < numRows - 1; k++)
        {
            for (int i = k, j = d - k; i < n; i += d, j += d)
            {
                ret += s[i];
                if (j < n)
                    ret += s[j];
            }
        }
        for (int i = numRows - 1; i < n; i += d)
        {
            ret += s[i];
        }
        return ret;
    }
};