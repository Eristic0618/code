#include <stdio.h>
#include <math.h>

int main()
{
    int m = 0;
    int n = 0;
    printf("从小到大输入两个0-10的十次方以内的数:");
    scanf("%d %d",&m,&n);//输入数字

    int found = 0;//有自幂数为1，没有为0
    
    if(0<=m && m<=10000000000 && m<=n && 0<=n && n<=10000000000)
    {
        for (int i = m; i<=n; i++)//遍历m-n以内的所有数
        {
            int x = 0;
            int num = i;
            int j = 0;
            while(num!=0)
            {
                num = num / 10;
                x++;//计算位数
            }
            num = i;
            int sum = 0;
            while(num!=0)
            {
                int y = pow((num%10),x);//pow计算以num%10为底的n次方
                num /= 10;
                sum += y;
            }   
            if(sum == i)//对比sum和i，如果相等为自幂数
            {
                printf("%d ",i);//按格式打印自幂数
                found = 1;
            }         
        }        
    }
    if(!found)//无自幂数
    {
        printf("no\n");
    }
    return 0;
}