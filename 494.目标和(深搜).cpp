// https://leetcode.cn/problems/target-sum/description/
// ����һ���Ǹ��������� nums ��һ������ target ��
// �������е�ÿ������ǰ��� '+' �� '-' ��Ȼ�������������������Թ���һ�� ���ʽ ��
// ���磬nums = [2, 1] �������� 2 ֮ǰ��� '+' ���� 1 ֮ǰ��� '-' ��Ȼ���������õ����ʽ "+2-1" ��
// ���ؿ���ͨ��������������ġ����������� target �Ĳ�ͬ ���ʽ ����Ŀ��
class Solution
{
public:
    int sum;
    int count;
    int target;

    int findTargetSumWays(vector<int> &nums, int _target)
    {
        target = _target;
        dfs(nums, 0);
        return count;
    }

    void dfs(vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            if (sum == target)
                count++;
            return;
        }
        sum += nums[i];
        dfs(nums, i + 1);
        sum -= nums[i] * 2;
        dfs(nums, i + 1);
        sum += nums[i];
        return;
    }
};