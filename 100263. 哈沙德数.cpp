// https://leetcode.cn/problems/harshad-number/description/
// ���һ�������ܹ����������λ�ϵ�����֮�����������֮Ϊ ��ɳ������Harshad number����
// ����һ������ x ����� x �� ��ɳ���� ���򷵻� x ������λ�ϵ�����֮�ͣ����򣬷��� -1 ��
class Solution
{
public:
    int sumOfTheDigitsOfHarshadNumber(int x)
    {
        int sum = 0;
        int temp = x;
        while (temp)
        {
            sum += temp % 10;
            temp /= 10;
        }
        if (x % sum == 0)
            return sum;
        return -1;
    }
};