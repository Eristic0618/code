#include <stdio.h>

#define offsetof(type, member) (size_t) & (((type *)0)->member)
// 1.��0ת����type*���͵�ָ��
// 2.ָ��member��ȡ��ַ
// 3.��ȡ���ĵ�ַת����size_t���ͣ����ܵõ�ƫ������
// �ο���http://t.csdnimg.cn/qcfX8

typedef struct Demo
{
    int a;
    double b;
    char c[];
} demo;

int main()
{
    printf("ƫ����:a=%d,b=%d,c=%d", offsetof(demo, a), offsetof(demo, b), offsetof(demo, c));
    return 0;
}