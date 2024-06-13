// https://leetcode.cn/problems/sum-of-all-subset-xor-totals/description/
// һ������� ����ܺ� ����Ϊ����������Ԫ�ذ�λ XOR �Ľ�����������Ϊ �� ��������ܺ�Ϊ 0 ��
// ���磬���� [2,5,6] �� ����ܺ� Ϊ 2 XOR 5 XOR 6 = 1 ��
// ����һ������ nums ��������� nums ��ÿ�� �Ӽ� �� ����ܺ� �����㲢������Щֵ���֮ �� ��
// ע�⣺�ڱ����У�Ԫ�� ��ͬ �Ĳ�ͬ�Ӽ�Ӧ ��� ������
// ���� a ������ b ��һ�� �Ӽ� ��ǰ�������ǣ��� b ɾ��������Ҳ���ܲ�ɾ����Ԫ���ܹ��õ� a ��
class Solution
{
public:
    int sum;
    int path;

    int subsetXORSum(vector<int> &nums)
    {
        dfs(nums, 0);
        return sum;
    }

    void dfs(vector<int> &nums, int pos)
    {
        sum += path;
        for (int i = pos; i < nums.size(); i++)
        {
            path ^= nums[i];
            dfs(nums, i + 1);
            path ^= nums[i];
        }
        return;
    }
};