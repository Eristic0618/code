// https://leetcode.cn/problems/lemonade-change/description/
// ������ˮ̯�ϣ�ÿһ������ˮ���ۼ�Ϊ 5 ��Ԫ���˿��Ŷӹ�����Ĳ�Ʒ�������˵� bills ֧����˳��һ�ι���һ����
// ÿλ�˿�ֻ��һ������ˮ��Ȼ�����㸶 5 ��Ԫ��10 ��Ԫ�� 20 ��Ԫ��������ÿ���˿���ȷ���㣬Ҳ����˵��������ÿλ�˿�����֧�� 5 ��Ԫ��
// ע�⣬һ��ʼ����ͷû���κ���Ǯ��
// ����һ���������� bills ������ bills[i] �ǵ� i λ�˿͸����ˡ�������ܸ�ÿλ�˿���ȷ���㣬���� true �����򷵻� false ��

// ̰���㷨
class Solution
{
public:
    int countfive;
    int countten;

    bool lemonadeChange(vector<int> &bills)
    {
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
                countfive++;
            else if (bills[i] == 10)
            {
                if (countfive == 0)
                    return false;
                countfive--;
                countten++;
            }
            else
            {
                if (countten && countfive)
                {
                    countten--;
                    countfive--;
                }
                else if (countfive >= 3)
                    countfive -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};