// https://www.nowcoder.com/share/jump/8993698061708573423699
// 现在有一个长度为 n 的正整数序列，其中只有一种数值出现了奇数次，其他数值均出现偶数次，请你找出那个出现奇数次的数值。
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