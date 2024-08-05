// https://leetcode.cn/problems/house-robber-ii/description/
// ����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݣ�ÿ�䷿�ڶ�����һ�����ֽ�����ط����еķ��ݶ� Χ��һȦ ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�
// ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ����� ��
// ����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ �ڲ���������װ�õ������ �������ܹ�͵�Ե�����߽�
class Solution
{
public:
    int rob1(vector<int> &nums, int begin, int end)
    {
        if (begin > end)
            return 0; // ������䲻���ڷ���0
        int n = end - begin + 1;
        vector<int> f(n);
        vector<int> g(n);
        f[0] = nums[begin];
        for (int i = 1; i < n; i++)
        {
            f[i] = g[i - 1] + nums[begin + i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[n - 1], g[n - 1]);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int steal = rob1(nums, 2, n - 2) + nums[0]; // �������ۣ�͵��һ�䷿���߲�͵��һ�䷿���������Ϊ������ҽ���1
        int not_steal = rob1(nums, 1, n - 1);
        return max(steal, not_steal);
    }
};