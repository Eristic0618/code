// 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数
void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void rotate(int *nums, int numsSize, int k)
{
    if (k >= numsSize)
        k %= numsSize;
    int mid = numsSize / 2;
    for (int i = 0; i < mid; i++)
    {
        Swap(nums + i, nums + (numsSize - 1 - i));
    }
    for (int i = 0; i < k / 2; i++)
    {
        Swap(nums + i, nums + (k - 1 - i));
    }
    for (int i = 0; i < (numsSize - k) / 2; i++)
    {
        Swap(nums + i + k, nums + (numsSize - 1 - i));
    }
}