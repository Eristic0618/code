// https://www.nowcoder.com/share/jump/8993698061708486568139
// ��һ�����ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӡ�
// ���ӣ�����һֻ���ӵ�3���³�������ô����5���¿�ʼ��ÿ������һֻ���ӡ�
// һ�µ�ʱ����һֻ���ӣ��������Ӷ��������ʵ�n���µ���������Ϊ���٣�
#include <stdio.h>

int main()
{
    int month;
    scanf("%d", &month);
    int rabbitnum = 0;
    int onemonth = 1;
    int twomonth = 0;
    int adult = 0;
    for (int i = 2; i <= month; i++)
    {
        adult += twomonth;
        twomonth = onemonth;
        onemonth = adult;
        rabbitnum = +onemonth + twomonth + adult;
    }
    printf("%d", rabbitnum);
    return 0;
}