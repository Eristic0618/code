// https://www.nowcoder.com/share/jump/8993698061708487486865
// ���еĶ������£����еĵ�һ��Ϊn���Ժ����Ϊǰһ���ƽ�����������е�ǰm��ĺ͡�
// ���������ж��飬ÿ��ռһ�У�����������n��n<10000����m(m<1000)��ɣ�n��m�ĺ�����ǰ������
// ����ÿ���������ݣ���������еĺͣ�ÿ������ʵ��ռһ�У�Ҫ�󾫶ȱ���2λС����
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        double *a = (double *)malloc(sizeof(double) * m);
        a[0] = (double)n;
        double sum = a[0];
        for (int i = 1; i < m; i++)
        {
            a[i] = sqrt(a[i - 1]);
            sum += a[i];
        }
        printf("%.2lf\n", sum);
    }
    return 0;
}