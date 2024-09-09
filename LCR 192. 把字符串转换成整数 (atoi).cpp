// https://leetcode.cn/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/description/
// ������ʵ��һ�� myAtoi(string s) ������ʹ���ܽ��ַ���ת����һ�� 32 λ�з������������� C/C++ �е� atoi ��������
//  ���� myAtoi(string s) ���㷨���£�
//  �����ַ������������õ�ǰ���ո�
//  �����һ���ַ������軹δ���ַ�ĩβ��Ϊ�����Ǹ��ţ���ȡ���ַ�������У��� ȷ�����ս���Ǹ������������� ������߶������ڣ���ٶ����Ϊ����
//  ������һ���ַ���ֱ��������һ���������ַ��򵽴�����Ľ�β���ַ��������ಿ�ֽ������ԡ�
//  ��ǰ�沽��������Щ����ת��Ϊ����������"123" -> 123�� "0032" -> 32�������û�ж������֣�������Ϊ 0 ����Ҫʱ���ķ��ţ��Ӳ��� 2 ��ʼ����
//  ������������� 32 λ�з���������Χ [?231,  231 ? 1] ����Ҫ�ض����������ʹ�䱣���������Χ�ڡ�������˵��С�� ?231 ������Ӧ�ñ��̶�Ϊ ?231 ������ 231 ? 1 ������Ӧ�ñ��̶�Ϊ 231 ? 1 ��
//  ����������Ϊ���ս����
class Solution
{
public:
    int myAtoi(string str)
    {
        if (str.empty())
            return 0;
        if (isalpha(str[0]))
            return 0;
        long ans = 0;
        int i = 0;
        int max = pow(2, 31) - 1, min = -pow(2, 31);
        while (str[i] == ' ')
            i++;
        int flag = 1;
        if (str[i] == '-')
            flag = -1, i++;
        else if (str[i] == '+')
            i++;
        while (i < str.size())
        {
            if (isdigit(str[i]))
            {
                ans = ans * 10 + flag * (str[i] - '0');
                if (ans > max)
                    return max;
                if (ans < min)
                    return min;
            }
            else
                return ans;
            i++;
        }
        return ans;
    }
};