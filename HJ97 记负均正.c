// ��������Ҫ�������������n��Ȼ������n�����������Ϊn�������и����ĸ�������������������ƽ��ֵ���������һλС����
// 0��������������Ҳ���Ǹ�������������㡣���û����������ƽ��ֵΪ0��
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int posnum = 0;
    int possum = 0;
    int negnum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            negnum++;
        else if (a[i] > 0)
        {
            posnum++;
            possum += a[i];
        }
    }
    double avg = 0.0;
    if (posnum != 0)
        avg = (double)possum / (double)posnum;
    printf("%d %.1f", negnum, avg);
    return 0;
}