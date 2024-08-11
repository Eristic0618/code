// https://leetcode.cn/problems/count-alternating-subarrays/description/
// ����һ������������nums ��
// ���һ���������� ������ ���� ���� Ԫ�ص�ֵ ��ͬ ����������ǳ�������������Ϊ ���������� ��
// �������� nums �н����������������
class Solution
{
public:
    long long countAlternatingSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        long long ret = 1, cur = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                cur = 1;
            else
                cur++;
            ret += cur;
        }
        return ret;
    }
};