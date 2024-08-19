// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/
// ��֪һ������Ϊ n �����飬Ԥ�Ȱ����������У����� 1 �� n �� ��ת �󣬵õ��������顣���磬ԭ���� nums = [0,1,2,4,5,6,7] �ڱ仯����ܵõ���
// ����ת 4 �Σ�����Եõ� [4,5,6,7,0,1,2]
// ����ת 7 �Σ�����Եõ� [0,1,2,4,5,6,7]
// ע�⣬���� [a[0], a[1], a[2], ..., a[n-1]] ��תһ�� �Ľ��Ϊ���� [a[n-1], a[0], a[1], a[2], ..., a[n-2]] ��
// ����һ��Ԫ��ֵ ������ͬ ������ nums ����ԭ����һ���������е����飬�����������ν����˶����ת�������ҳ������������е� ��СԪ�� ��
// ��������һ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        int k = nums[right];
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > k)
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};