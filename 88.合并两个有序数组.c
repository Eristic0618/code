// 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
// 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
// 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n
// 其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    if (n == 0)
        return;
    if (m == 0)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[i] = nums2[i];
        }
    }
    int n1 = m - 1;
    int n2 = n - 1;
    int num = m + n - 1;
    while (n1 >= 0 && n2 >= 0)
    {
        if (nums1[n1] > nums2[n2])
        {
            nums1[num--] = nums1[n1--];
        }
        else
        {
            nums1[num--] = nums2[n2--];
        }
    }
    if (n2 >= 0)
    {
        for (int i = 0; i <= n2; i++)
        {
            nums1[i] = nums2[i];
        }
    }
}
