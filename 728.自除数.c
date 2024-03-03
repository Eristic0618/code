// 自除数 是指可以被它包含的每一位数整除的数。
// 例如，128 是一个 自除数 ，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
// 自除数 不允许包含 0 。
// 给定两个整数 left 和 right ，返回一个列表，列表的元素是范围 [left, right] 内所有的 自除数 。
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