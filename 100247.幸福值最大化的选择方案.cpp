// https://leetcode.cn/problems/maximize-happiness-of-selected-children/description/
// ����һ������Ϊ n ������ happiness ���Լ�һ�� ������ k ��
// n ������վ��һ�ӣ����е� i �����ӵ� �Ҹ�ֵ �� happiness[i] ����ƻ���֯ k ��ɸѡ���� n ��������ѡ�� k �����ӡ�
// ��ÿһ��ѡ��һ������ʱ������ ��δ ��ѡ�еĺ��ӵ� �Ҹ�ֵ ������ 1 ��ע�⣬�Ҹ�ֵ ���� ��ɸ�������ֻ������������������²Ż���١�
// ѡ�� k �����ӣ���ʹ��ѡ�еĺ����Ҹ�ֵ֮����󣬷������ܹ��õ��� ���ֵ ��
class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long happysum = 0;
        int sub = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for (int i = 0; i < k; ++i)
        {
            if (happiness[i] - sub > 0)
            {
                happysum += happiness[i] - sub;
            }
            else
            {
                happysum += 0;
            }
            sub++;
        }
        return happysum;
    }
};