//ʵ�ֺ����ж�year�ǲ�������
#include <stdio.h>

int Leap(int x)
{
    if (((x % 4 == 0) && (x % 100 != 0)) || (x % 400 == 0))
        return 1;
    else
        return 0;
}

int main()
{
    int year = 0;
    scanf("%d", &year);
    if (Leap(year))
        printf("������\n");
    else
        printf("��������\n");
    return 0;
}