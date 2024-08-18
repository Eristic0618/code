// https://leetcode.cn/problems/find-peak-element/description/
// ��ֵԪ����ָ��ֵ�ϸ������������ֵ��Ԫ�ء�
// ����һ���������� nums���ҵ���ֵԪ�ز�������������������ܰ��������ֵ������������£����� �κ�һ����ֵ ����λ�ü��ɡ�
// ����Լ��� nums[-1] = nums[n] = -�� ��
// �����ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨����������⡣
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};