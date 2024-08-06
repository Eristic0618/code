// https://leetcode.cn/problems/delete-and-earn/description/
// ����һ���������� nums ������Զ�������һЩ������
// ÿ�β����У�ѡ������һ�� nums[i] ��ɾ��������� nums[i] �ĵ�����֮�������ɾ�� ���� ���� nums[i] - 1 �� nums[i] + 1 ��Ԫ�ء�
// ��ʼ��ӵ�� 0 ����������������ͨ����Щ������õ���������
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        const int N = 10001;
        int n = nums.size();
        vector<int> sum(N);
        for (auto i : nums)
            sum[i] += i;
        vector<int> f(N);
        auto g = f;
        f[0] = sum[0];
        for (int i = 1; i < N; i++)
        {
            f[i] = g[i - 1] + sum[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[N - 1], g[N - 1]);
    }
};