// �������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��
// 1. �÷���һ�������б��������ӡ
// 2. n Ϊ��������0 < n <= 5
int *printNumbers(int n, int *returnSize)
{
    static int array[100000] = {0};
    int max = 1;
    while (n--)
    {
        max *= 10;
    }
    int i = 0;
    for (i = 1; i < max; i++)
    {
        array[i - 1] = i;
    }
    *returnSize = i - 1;
    return array;
}