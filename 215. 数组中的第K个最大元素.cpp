// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
// ������������ nums ������ k���뷵�������е� k ������Ԫ�ء�
// ��ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
// �������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣
// ���ȼ�����
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k);
        for (size_t i = k; i < nums.size(); ++i)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};