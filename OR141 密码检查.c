// С��ͬѧ���������һ����վ�����û�ע���˻���ʱ����Ҫ�����˻������룬Ϊ�˼�ǿ�˻��İ�ȫ�ԣ�С��������ǿ����һ��Ҫ��
// 1. ����ֻ���ɴ�д��ĸ��Сд��ĸ�����ֹ��ɣ�
// 2. ���벻�������ֿ�ͷ��
// 3. ���������ٳ��ִ�д��ĸ��Сд��ĸ�������������ַ������е����֣�
// 4. ���볤������Ϊ8
// ����С���ܵ���n�����룬��������д�����ж���Щ��������Щ�Ǻ��ʵģ���Щ�ǲ��Ϸ��ġ�
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    int n;
    scanf("%d", &n);
    char pwr[110];
    while (n--)
    {
        bool flag = true;
        scanf("%s", pwr);
        int i = 0;
        int len = strlen(pwr);
        int digit = 0, upper = 0, lower = 0;
        if (isdigit(pwr[0]) || len < 8)
        {
            flag = false;
        }
        while (pwr[i] != '\0')
        {
            if (!isdigit(pwr[i]) && !isupper(pwr[i]) && !islower(pwr[i]))
                flag = false;
            if (digit == 0 && isdigit(pwr[i]))
                digit = 1;
            if (upper == 0 && isupper(pwr[i]))
                upper = 1;
            if (lower == 0 && islower(pwr[i]))
                lower = 1;
            i++;
        }
        if (digit + upper + lower < 2)
            flag = false;
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}