//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ
#include <stdio.h>

int main()
{
    int soda = 20;
    int empt = soda;
    int drink = 0;
    do
    {
        drink = drink + soda;
        empt = soda;
        soda = 0;
        while (empt > 1)
        {
            soda++;
            empt = empt - 2;
        }
    } while (soda != 0);
    printf("%d", drink);
    return 0;
}