#include <stdio.h>

int Add(int x,int y)
{
    int z = 0;
    z = x + y;
    return z;
}

int main()
{
    int A = 0;
    int B = 0;
    printf("请输入0-100000000之间的数字:");
    scanf("%d%d",&A,&B);
    if ((0 < A && A <= 100000000) && (0 < B && B <= 100000000)) 
    {
        int sum = Add(A,B);
        printf("%d\n",sum);
    }
    else
    {
        printf("输入错误\n");
    }
    return 0;
} 

