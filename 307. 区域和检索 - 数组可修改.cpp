// https://leetcode.cn/problems/range-sum-query-mutable/description/
//  给你一个数组 nums ，请你完成两类查询。
//  其中一类查询要求 更新 数组 nums 下标对应的值
//  另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right
//  实现 NumArray 类：
//  NumArray(int[] nums) 用整数数组 nums 初始化对象
//  void update(int index, int val) 将 nums[index] 的值 更新 为 val
//  int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 （即，nums[left] + nums[left + 1], ..., nums[right]）
class NumArray
{
public:
    vector<int> segmentTree;
    int sz;

    void BuildTree(int l, int r, vector<int> &nums, int i) // 建线段树
    {
        if (l == r) // 找到只有单个元素的区间，赋值
        {
            segmentTree[i] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        BuildTree(l, mid, nums, 2 * i + 1);
        BuildTree(mid + 1, r, nums, 2 * i + 2);
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    void change(int l, int r, int i, int index, int val) // 单点修改
    {
        if (l == r) // 找到待修改节点
        {
            segmentTree[i] = val; // 修改节点值
            return;
        }
        int mid = l + (r - l) / 2;
        if (mid >= index) // 判断节点区间中是否包含待修改节点
            change(l, mid, 2 * i + 1, index, val);
        else
            change(mid + 1, r, 2 * i + 2, index, val);
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2]; // 修改节点值
    }

    int ask(int l, int r, int i, int st, int ed) // 区间查询
    {
        if (l >= st && r <= ed) // 节点是待查找区间的子集，直接返回
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