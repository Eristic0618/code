// 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
// 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
// 必须在不使用库内置的 sort 函数的情况下解决这个问题。
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int left = -1, right = n, i = 0, tmp = 0;
        while (i < right)
        {
            if (nums[i] == 0)
                swap(nums[++left], nums[i++]);
            else if (nums[i] == 1)
                i++;
            else
                swap(nums[--right], nums[i]);
        }
    }
};