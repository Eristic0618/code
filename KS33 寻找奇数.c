// https://www.nowcoder.com/share/jump/8993698061708573423699
// ������һ������Ϊ n �����������У�����ֻ��һ����ֵ�����������Σ�������ֵ������ż���Σ������ҳ��Ǹ����������ε���ֵ��
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    long *nums = (long *)malloc(sizeof(long) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", nums + i);
    }
    long ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret ^= nums[i];
    }
    printf("%ld", ret);
    return 0;
}