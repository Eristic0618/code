// 整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。
int convertInteger(int A, int B)
{
    unsigned int x = A ^ B;
    int n = 0;
    while (x)
    {
        if (x & 1 != 0)
            n++;
        x = x >> 1;
    }
    return n;
}