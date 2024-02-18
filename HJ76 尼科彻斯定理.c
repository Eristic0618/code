// 验证尼科彻斯定理，即：任何一个整数m的立方都可以写成m个连续奇数之和。
// 例如：
// 1^3=1
// 2^3=3+5
// 3^3=7+9+11
// 4^3=13+15+17+19
// 输入一个正整数m（m≤100），将m的立方写成m个连续奇数之和的形式输出。
#include <stdio.h>

int main()
{
    int m;
    scanf("%d", &m);
    int count, left;
    left = m * m - m + 1;
    printf("%d", left);
    for (int i = 1; i < m; i++)
    {
        printf("+%d", left + 2 * i);
    }
    return 0;
}