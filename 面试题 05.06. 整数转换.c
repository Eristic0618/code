// ����ת������дһ��������ȷ����Ҫ�ı伸��λ���ܽ�����Aת������B��
int convertInteger(int A, int B)
{
    unsigned int x = A ^ B;
    int n = 0;
    while (x)
    {
        if (x & 1 != 0)
            n++;
        x = x >> 1;
    }
    return n;
}