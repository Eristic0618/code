// ��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����
// �����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ���������
// ���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1+2+4+7+14=28��
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int sum = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        if (sum == i)
            count++;
    }
    printf("%d", count);
    return 0;
}