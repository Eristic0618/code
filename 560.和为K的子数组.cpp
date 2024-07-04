// https://leetcode.cn/problems/subarray-sum-equals-k/description/
// ����һ���������� nums ��һ������ k ������ͳ�Ʋ����� �������к�Ϊ k ��������ĸ��� ��
// ��������������Ԫ�ص������ǿ�����

// ǰ׺��+��ϣ��
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        int count = 0;
        int sum = 0;
        hash[0] = 1;
        for (auto i : nums)
        {
            sum += i;
            count += hash[sum - k];
            hash[sum]++;
        }
        return count;
    }
};