#include <stdio.h>
#include <math.h>

int main()
{
    int m = 0;
    int n = 0;
    printf("��С������������0-10��ʮ�η����ڵ���:");
    scanf("%d %d",&m,&n);//��������

    int found = 0;//��������Ϊ1��û��Ϊ0
    
    if(0<=m && m<=10000000000 && m<=n && 0<=n && n<=10000000000)
    {
        for (int i = m; i<=n; i++)//����m-n���ڵ�������
        {
            int x = 0;
            int num = i;
            int j = 0;
            while(num!=0)
            {
                num = num / 10;
                x++;//����λ��
            }
            num = i;
            int sum = 0;
            while(num!=0)
            {
                int y = pow((num%10),x);//pow������num%10Ϊ�׵�n�η�
                num /= 10;
                sum += y;
            }   
            if(sum == i)//�Ա�sum��i��������Ϊ������
            {
                printf("%d ",i);//����ʽ��ӡ������
                found = 1;
            }         
        }        
    }
    if(!found)//��������
    {
        printf("no\n");
    }
    return 0;
}