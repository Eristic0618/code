// 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int count = 0;
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int smallsize = nums1Size;
    if (nums1Size > nums2Size)
        smallsize = nums2Size;
    int *sec = (int *)malloc(sizeof(int) * smallsize);
    int i1 = 0, i2 = 0;
    while (i1 < nums1Size && i2 < nums2Size)
    {
        if (i1 < nums1Size && i2 < nums2Size && nums1[i1] == nums2[i2])
        {
            if (count >= 1 && sec[count - 1] == nums1[i1])
                count--;
            sec[count] = nums1[i1];
            count++;
            i1++;
            i2++;
        }
        if (i1 < nums1Size && i2 < nums2Size && nums1[i1] < nums2[i2])
            i1++;
        if (i1 < nums1Size && i2 < nums2Size && nums1[i1] > nums2[i2])
            i2++;
    }
    for (int i = 0; i < count; i++)
        printf("%d ", sec[i]);
    *returnSize = count;
    return sec;
}