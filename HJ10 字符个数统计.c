// ��дһ�������������ַ����к��еĲ�ͬ�ַ��ĸ������ַ��� ASCII �뷶Χ��( 0~127 ������ 0 �� 127 )
// ���б�ʾ���������������ַ�����ڷ�Χ�ڵĲ���ͳ�ơ������ͬ���ַ�ֻ����һ��
// ���磬�����ַ��� abaca ���ԣ��� a��b��c ���ֲ�ͬ���ַ��������� 3 ��
#include <stdio.h>
#include <string.h>

int main()
{
    char ch[500];
    scanf("%s", ch);
    int len = strlen(ch);
    int hash[128] = {0};
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (ch[i] != '\n' && (int)ch[i] >= 0 && (int)ch[i] <= 127)
        {
            hash[(int)ch[i]]++;
        }
    }
    for (int i = 0; i < 128; i++)
    {
        if (hash[i] != 0)
            count++;
    }
    printf("%d", count);
    return 0;
}