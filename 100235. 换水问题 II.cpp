// https://leetcode.cn/problems/water-bottles-ii/description/
// ������������ numBottles �� numExchange ��
// numBottles ���������ӵ�е���ˮƿ��������һ�β����У������ִ�����²���֮һ��
// �ȵ�������������ˮƿ��ʹ���Ǳ�ɿ�ˮƿ��
// �� numExchange ����ˮƿ����һ����ˮƿ��Ȼ�󣬽� numExchange ��ֵ���� 1 ��
// ע�⣬�㲻��ʹ����ͬ�� numExchange ֵ����������ˮƿ�����磬��� numBottles == 3 ���� numExchange == 1 �������� 3 ����ˮƿ������ 3 ����ˮƿ��
// ������ ��� ���Ժȵ�����ƿˮ��
class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int ret = numBottles, empty = numBottles, full = 0;
        while (empty >= numExchange)
        {
            full++;
            empty -= numExchange;
            numExchange++;
            ret += full;
            empty += full;
            full = 0;
        }
        return ret;
    }
};