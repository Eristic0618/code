// 小明同学最近开发了一个网站，在用户注册账户的时候，需要设置账户的密码，为了加强账户的安全性，小明对密码强度有一定要求：
// 1. 密码只能由大写字母，小写字母，数字构成；
// 2. 密码不能以数字开头；
// 3. 密码中至少出现大写字母，小写字母和数字这三种字符类型中的两种；
// 4. 密码长度至少为8
// 现在小明受到了n个密码，他想请你写程序判断这些密码中哪些是合适的，哪些是不合法的。
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    int n;
    scanf("%d", &n);
    char pwr[110];
    while (n--)
    {
        bool flag = true;
        scanf("%s", pwr);
        int i = 0;
        int len = strlen(pwr);
        int digit = 0, upper = 0, lower = 0;
        if (isdigit(pwr[0]) || len < 8)
        {
            flag = false;
        }
        while (pwr[i] != '\0')
        {
            if (!isdigit(pwr[i]) && !isupper(pwr[i]) && !islower(pwr[i]))
                flag = false;
            if (digit == 0 && isdigit(pwr[i]))
                digit = 1;
            if (upper == 0 && isupper(pwr[i]))
                upper = 1;
            if (lower == 0 && islower(pwr[i]))
                lower = 1;
            i++;
        }
        if (digit + upper + lower < 2)
            flag = false;
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}