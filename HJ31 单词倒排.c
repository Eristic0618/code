// https://www.nowcoder.com/share/jump/8993698061708484704803
// 对字符串中的所有单词进行倒排。
// 说明：
// 1、构成单词的字符只有26个大写或小写英文字母；
// 2、非构成单词的字符均视为单词间隔符；
// 3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
// 4、每个单词最长20个字母；
// 示例1
// 输入：I am a student
// 输出：student a am I
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