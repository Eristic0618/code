// https://www.nowcoder.com/share/jump/8993698061708484704803
// ���ַ����е����е��ʽ��е��š�
// ˵����
// 1�����ɵ��ʵ��ַ�ֻ��26����д��СдӢ����ĸ��
// 2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������
// 3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������
// 4��ÿ�������20����ĸ��
// ʾ��1
// ���룺I am a student
// �����student a am I
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *word[500];
    char str[10000];
    gets(str);
    int len = strlen(str);
    char *tmp = str;
    int count = 0;
    while (*(tmp++))
    {
        if ((*tmp) < 'A' || ((*tmp) > 'Z' && (*tmp) < 'a') || (*tmp) > 'z')
            count++;
    }
    int right = len - 1;
    int wordlen = 0;
    for (int i = count - 1; i >= 0; i--)
    {
        word[i] = (char *)malloc(sizeof(char) * 20);
        wordlen = 0;
        while ((str[right] >= 'A' && str[right] <= 'Z') || (str[right] >= 'a' && str[right] <= 'z'))
        {
            right--;
        }
        int cur = right + 1;
        while ((str[cur] >= 'A' && str[cur] <= 'Z') || (str[cur] >= 'a' && str[cur] <= 'z'))
        {
            word[i][wordlen++] = str[cur];
            cur++;
        }
        word[i][wordlen] = '\0';
        right--;
    }
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%s ", word[i]);
    }
    return 0;
}