// https://leetcode.cn/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k/description/
// ����һ�������� k �����������һ������ nums = [1] ��
// ����Զ�����ִ������ ���� ���� ���� ����������Ϊ�㣩��
// ѡ�������е��κ�һ��Ԫ�أ�Ȼ������ֵ ���� 1 ��
// ���������е��κ�һ��Ԫ�أ�Ȼ�������ӵ������ĩβ��
// ����ʹ����������Ԫ��֮ �� ���ڻ���� k ����� ���� ����������
class Solution
{
public:
    int ret;

    void dfs(int k, int sum, int max)
    {
        if (max + max * max < k)
        {
            max++;
            sum++;
            ret++;
            dfs(k, sum, max);
        }
        else
        {
            while (sum < k)
            {
                sum += max;
                ret++;
            }
            return;
        }
    }

    int minOperations(int k)
    {
        vector<int> nums(1, 1);
        dfs(k, 1, 1);
        return ret;
    }
};