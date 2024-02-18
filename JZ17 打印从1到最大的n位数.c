// 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
// 1. 用返回一个整数列表来代替打印
// 2. n 为正整数，0 < n <= 5
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