// Lily�Ͽ�ʱʹ����ĸ����ͼƬ��С������ѧϰӢ�ﵥ�ʣ�ÿ�ζ���Ҫ����ЩͼƬ���մ�С��ASCII��ֵ��С���������պá�
// ���Ҹ�Lily��æ��ͨ����������
// Lilyʹ�õ�ͼƬʹ���ַ�"A"��"Z"��"a"��"z"��"0"��"9"��ʾ��
//  ����������
//  һ�У�һ���ַ������ַ����е�ÿ���ַ���ʾһ��Lilyʹ�õ�ͼƬ��
//  ���������
//  Lily������ͼƬ���մ�С�����˳�����
// ʾ��1
// ���룺Ihave1nose2hands10fingers
// �����0112Iaadeeefghhinnnorsssv
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    char ch[1000];
    scanf("%s", ch);
    int len = strlen(ch);
    int *sort = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        sort[i] = (int)ch[i];
    }
    qsort(sort, len, sizeof(int), cmp);
    for (int i = 0; i < len; i++)
    {
        printf("%c", (char)sort[i]);
    }
    return 0;
}