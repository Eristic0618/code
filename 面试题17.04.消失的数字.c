// ����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
int missingNumber(int *nums, int numsSize)
{
    int n = numsSize;
    int x = 0;
    for (int i = 0; i <= n; i++)
    {
        x ^= i;
    }
    for (int i = 0; i < n; i++)
    {
        x ^= nums[i];
    }
    return x;
}
