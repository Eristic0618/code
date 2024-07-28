// https://leetcode.cn/problems/min-cost-climbing-stairs/description/
// ����һ���������� cost ������ cost[i] �Ǵ�¥�ݵ� i ��̨����������Ҫ֧���ķ��á�һ����֧���˷��ã�����ѡ��������һ����������̨�ס�
// �����ѡ����±�Ϊ 0 ���±�Ϊ 1 ��̨�׿�ʼ��¥�ݡ�
// ������㲢���شﵽ¥�ݶ�������ͻ��ѡ�
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0; // �±꼴Ϊ̨��������Ϊ���Դ�0��1��ʼ�������������ط��ĳ�ʼֵ��Ϊ0
        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); // ��i�׵���ͻ���ȡ�����ȵ�i-2��+���ú��ȵ�i-1��+���õĽ�Сֵ
        }
        return dp[n];
    }
};