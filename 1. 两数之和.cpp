// https://leetcode.cn/problems/two-sum/description/
// ����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
// ����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
// ����԰�����˳�򷵻ش𰸡�
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!hash.count(target - nums[i]))
                hash[nums[i]] = i;
            else
                return {hash[target - nums[i]], i};
        }
        return {-1, -1};
    }
};