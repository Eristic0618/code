#include <stdio.h>

#define offsetof(type, member) (size_t) & (((type *)0)->member)
// 1.将0转换成type*类型的指针
// 2.指向member后，取地址
// 3.将取到的地址转换成size_t类型，就能得到偏移量了
// 参考：http://t.csdnimg.cn/qcfX8

typedef struct Demo
{
    int a;
    double b;
    char c[];
} demo;

int main()
{
    printf("偏移量:a=%d,b=%d,c=%d", offsetof(demo, a), offsetof(demo, b), offsetof(demo, c));
    return 0;
}