// �ݹ�ʵ��n��k�η�
#include <stdio.h>

int Power(int a, int b)
{
    int c = a;
    if(b>1)
    {
        int c = a * Power(a, b - 1);
        return c;
    }
    else
        return c;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int ret = Power(n, k);
    printf("%d", ret);
    return 0;
}