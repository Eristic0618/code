// ���� s ������ 1 �� n ��������
// ���ҵ��ǣ���Ϊ���ݴ��󣬵��¼�������ĳһ�����ָ����˳��˼������������һ�����ֵ�ֵ�����¼��϶�ʧ��һ�����ֲ��� ��һ�������ظ� ��
// ����һ������ nums �����˼��� S ���������Ľ����
// �����ҳ��ظ����ֵ����������ҵ���ʧ�����������������������ʽ���ء�
int cmp(int *a, int *b)
{
    return *a - *b;
}

int *findErrorNums(int *nums, int numsSize, int *returnSize)
{
    int *a = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 1; i++)
    {
        int prev = nums[i];
        int cur = nums[i + 1];
        if (prev == cur)
        {
            a[0] = prev;
        }
        if (nums[0] != 1)
            a[1] = 1;
        if (nums[numsSize - 1] != numsSize)
            a[1] = numsSize;
        if (cur - prev > 1)
            a[1] = prev + 1;
    }
    return a;
}