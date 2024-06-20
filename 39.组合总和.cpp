// https://leetcode.cn/problems/combination-sum/description/
// ����һ�� ���ظ�Ԫ�� ���������� candidates ��һ��Ŀ������ target ���ҳ� candidates �п���ʹ���ֺ�ΪĿ���� target �� ���� ��ͬ���
// �����б���ʽ���ء�����԰� ����˳�� ������Щ��ϡ�
// candidates �е� ͬһ�� ���ֿ��� �������ظ���ѡȡ ���������һ�����ֵı�ѡ������ͬ������������ǲ�ͬ�ġ�
// ���ڸ��������룬��֤��Ϊ target �Ĳ�ͬ��������� 150 ����
class Solution
{
public:
    vector<vector<int>> ret;
    vector<int> path;
    int target;

    vector<vector<int>> combinationSum(vector<int> &candidates, int _target)
    {
        target = _target;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0);
        return ret;
    }

    void dfs(vector<int> &nums, int sum)
    {
        if (sum == target)
        {
            ret.push_back(path);
            return;
        }
        if (sum > target)
            return;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!path.empty() && nums[i] < path.back())
                continue;
            path.push_back(nums[i]);
            dfs(nums, sum + nums[i]);
            path.pop_back();
        }
        return;
    }
};