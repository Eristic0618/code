// ����һ���������� nums ���������Ǵ��� Ψһ�� һ��������� ��
// �����ҳ������е����Ԫ�ز�������Ƿ� ������������ÿ���������ֵ����� ������ǣ��򷵻� ���Ԫ�ص��±� �����򷵻� -1 ��
int cmp(int *a, int *b)
{
    return *a - *b;
}

int dominantIndex(int *nums, int numsSize)
{
    int maxi = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > nums[maxi])
            maxi = i;
    }
    int max = nums[maxi];
    qsort(nums, numsSize, sizeof(int), cmp);
    if (max >= nums[numsSize - 2] * 2)
        return maxi;
    else
        return -1;
}