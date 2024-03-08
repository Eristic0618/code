// ����һ���� n ������������ nums ������ nums[i] ������ [1, n] �ڡ�
// �����ҳ������� [1, n] ��Χ�ڵ�û�г����� nums �е����֣������������ʽ���ؽ����
int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
    int *hash = (int *)malloc(sizeof(int) * numsSize);
    memset(hash, 0, sizeof(int) * numsSize);
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        hash[nums[i] - 1]++;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (hash[i] == 0)
        {
            count++;
        }
    }
    *returnSize = count;
    int *ret = (int *)malloc(sizeof(int) * count);
    int j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (hash[i] == 0)
        {
            ret[j++] = i + 1;
        }
    }
    return ret;
}