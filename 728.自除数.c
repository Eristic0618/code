// �Գ��� ��ָ���Ա���������ÿһλ������������
// ���磬128 ��һ�� �Գ��� ����Ϊ 128 % 1 == 0��128 % 2 == 0��128 % 8 == 0��
// �Գ��� ��������� 0 ��
// ������������ left �� right ������һ���б��б��Ԫ���Ƿ�Χ [left, right] �����е� �Գ��� ��
int *selfDividingNumbers(int left, int right, int *returnSize)
{
    int *ret = (int *)malloc(sizeof(int) * right);
    int count = 0;
    for (int i = left; i <= right; i++)
    {
        bool flag = true;
        int tmp = i;
        while (tmp)
        {
            int dig = tmp % 10;
            if (dig == 0 || i % dig != 0)
                flag = false;
            tmp /= 10;
        }
        if (flag)
            ret[count++] = i;
    }
    *returnSize = count;
    return ret;
}