//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//写一个程序来确定谁是凶手

#include <stdio.h>

int main()
{
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int i = 0;
    for (i = 1; i < 5; i++) // i为几就是第几个人说了假话
    {
        A = 0;
        B = 0;
        C = 0;
        D = 0;
        if (i == 1)
        {
            A++;
            C++;
            D = D + 1 - 1;//谁的值为1就是谁被指认为凶手
        }
        else if (i == 2)
        {
            D = D + 1 - 1;
        }
        else if (i == 3)
        {
            C++;
        }
        else if (i == 4)
        {
            C++;
            D++;
        }
        if (A + B + C + D == 1)
            break;
    }
    printf("%c", 64 + i);
    return 0;
}