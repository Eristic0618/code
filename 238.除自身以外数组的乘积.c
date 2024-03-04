// ����һ���������� nums������ ���� answer ������ answer[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻� ��
// ��Ŀ���� ��֤ ���� nums֮������Ԫ�ص�ȫ��ǰ׺Ԫ�غͺ�׺�ĳ˻�����  32 λ ������Χ�ڡ�
// �� ��Ҫʹ�ó��������� O(n) ʱ�临�Ӷ�����ɴ��⡣
int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
    int *leftmul = (int *)malloc(sizeof(int) * numsSize);
    leftmul[0] = 0;
    int *rightmul = (int *)malloc(sizeof(int) * numsSize);
    rightmul[numsSize - 1] = 0;
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 1; i < numsSize; i++)
    {
        int j = numsSize - 1 - i;
        if (i - 1 != 0)
            leftmul[i] = leftmul[i - 1] * nums[i - 1];
        else
            leftmul[i] = nums[i - 1];
        if (j + 1 != numsSize - 1)
            rightmul[j] = rightmul[j + 1] * nums[j + 1];
        else
            rightmul[j] = nums[j + 1];
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (i == 0)
            ret[i] = rightmul[i];
        else if (i == numsSize - 1)
            ret[i] = leftmul[i];
        else
            ret[i] = leftmul[i] * rightmul[i];
    }
    *returnSize = numsSize;
    return ret;
}