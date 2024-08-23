// https://leetcode.cn/problems/subarray-sums-divisible-by-k/description/
// ����һ���������� nums ��һ������ k ����������Ԫ��֮�Ϳɱ� k �����ģ��������ǿգ� ������ ����Ŀ��
// ������ ������� ���� ���֡�
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        int ret = 0;
        int sum = 0;
        hash[0] = 1;
        for (auto i : nums)
        {
            sum += i;
            ret += hash[(sum % k + k) % k];
            hash[(sum % k + k) % k]++;
        }
        return ret;
    }
};