// https://leetcode.cn/problems/range-sum-query-mutable/description/
//  ����һ������ nums ��������������ѯ��
//  ����һ���ѯҪ�� ���� ���� nums �±��Ӧ��ֵ
//  ��һ���ѯҪ�󷵻����� nums ������ left ������ right ֮�䣨 ���� ����numsԪ�ص� �� ������ left <= right
//  ʵ�� NumArray �ࣺ
//  NumArray(int[] nums) ���������� nums ��ʼ������
//  void update(int index, int val) �� nums[index] ��ֵ ���� Ϊ val
//  int sumRange(int left, int right) �������� nums ������ left ������ right ֮�䣨 ���� ����numsԪ�ص� �� ������nums[left] + nums[left + 1], ..., nums[right]��
class NumArray
{
public:
    vector<int> segmentTree;
    int sz;

    void BuildTree(int l, int r, vector<int> &nums, int i) // ���߶���
    {
        if (l == r) // �ҵ�ֻ�е���Ԫ�ص����䣬��ֵ
        {
            segmentTree[i] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        BuildTree(l, mid, nums, 2 * i + 1);
        BuildTree(mid + 1, r, nums, 2 * i + 2);
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    void change(int l, int r, int i, int index, int val) // �����޸�
    {
        if (l == r) // �ҵ����޸Ľڵ�
        {
            segmentTree[i] = val; // �޸Ľڵ�ֵ
            return;
        }
        int mid = l + (r - l) / 2;
        if (mid >= index) // �жϽڵ��������Ƿ�������޸Ľڵ�
            change(l, mid, 2 * i + 1, index, val);
        else
            change(mid + 1, r, 2 * i + 2, index, val);
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2]; // �޸Ľڵ�ֵ
    }

    int ask(int l, int r, int i, int st, int ed) // �����ѯ
    {
        if (l >= st && r <= ed) // �ڵ��Ǵ�����������Ӽ���ֱ�ӷ���
            return segmentTree[i];
        int ans = 0;
        int mid = l + (r - l) / 2;
        if (mid >= st)
            ans += ask(l, mid, 2 * i + 1, st, ed);
        if (mid < ed)
            ans += ask(mid + 1, r, 2 * i + 2, st, ed);
        return ans;
    }

public:
    NumArray(vector<int> &nums)
        : sz(nums.size()), segmentTree(nums.size() * 5)
    {
        BuildTree(0, sz - 1, nums, 0);
    }

    void update(int index, int val)
    {
        change(0, sz - 1, 0, index, val);
    }

    int sumRange(int left, int right)
    {
        return ask(0, sz - 1, 0, left, right);
    }
};