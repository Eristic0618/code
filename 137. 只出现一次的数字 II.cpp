// https://leetcode.cn/problems/single-number-ii/description/
// ����һ���������� nums ����ĳ��Ԫ�ؽ����� һ�� �⣬����ÿ��Ԫ�ض�ǡ���� ���� �������ҳ��������Ǹ�ֻ������һ�ε�Ԫ�ء�
// �������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨��ʹ�ó������ռ�����������⡣
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
            hash[nums[i]]++;
        int ans;
        for (auto &[key, value] : hash)
        {
            if (value == 1)
                ans = key;
        }
        return ans;
    }
};