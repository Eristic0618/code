// ʹ���������֪ʶ��дһ�������жϵ�ǰ�����Ǵ�˻���С�ˣ������С�˷���1������Ǵ�˷���0.
#include <stdio.h>

int Check_sys()
{
    union
    {
        int a = 1;
        char c;
    } un;
    return un.c;
}

int main()
{
    int ret = Check_sys();
    if (ret == 1)
    {
        printf("С��\n");
    }
    else
    {
        printf("���\n");
    }
    return 0;
}