// 使用联合体的知识，写一个函数判断当前机器是大端还是小端，如果是小端返回1，如果是大端返回0.
#include <stdio.h>

int Check_sys()
{
    union
    {
        int a = 1;
        char c;
    } un;
    return un.c;
}

int main()
{
    int ret = Check_sys();
    if (ret == 1)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }
    return 0;
}