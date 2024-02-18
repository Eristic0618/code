// 有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组
// 比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。请问，给定这样一个旋转数组，求数组中的最小值。
int minNumberInRotateArray(int *nums, int numsLen)
{
    // 二分法
    int left = 0, right = numsLen - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (mid == 0 && nums[mid] < nums[numsLen - 1])
            return nums[mid];
        if (nums[mid + 1] < nums[mid])
            return nums[mid + 1];
        if (nums[mid] < nums[mid - 1])
            return nums[mid];
        if (nums[mid] < nums[left])
            right = mid;
        if (nums[mid] > nums[right])
            left = mid;
        else
            right--;
    }
    return -1;
}