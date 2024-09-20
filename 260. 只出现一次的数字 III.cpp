// https://leetcode.cn/problems/single-number-iii/description/
//  ����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε�������Ԫ�ء�����԰� ����˳�� ���ش𰸡�
//  �������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨�ҽ�ʹ�ó�������ռ�����������⡣
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        if (nums.size() == 2)
            return nums;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
            hash[nums[i]]++;
        vector<int> ans;
        for (auto &[key, value] : hash)
        {
            if (value == 1)
                ans.push_back(key);
        }
        return ans;
    }
};