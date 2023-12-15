// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char *s)
{
    int hash[128] = {0};
    int left = 0;
    int right = 0;
    int sz = strlen(s);
    int ret = 0;
    if (sz == 0)
    {
        return 0;
    }
    else if (sz == 1)
    {
        return 1;
    }
    while (right < sz)
    {
        hash[s[right]]++;
        while (hash[s[right]] > 1)
        {
            hash[s[left++]]--;
        }
        if (right - left + 1 >= ret)
        {
            ret = right - left + 1;
        }
        right++;
    }
    return ret;
}

int main()
{
    char s[] = "eeydgwdykpv";
    int ret = lengthOfLongestSubstring(s);
    printf("%d", ret);
    return 0;
}