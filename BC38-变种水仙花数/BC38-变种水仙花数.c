//����ˮ�ɻ��� - Lily Number������������֣����м��ֳ��������֣�����1461 ���Բ�ֳɣ�1��461��,��14��61��,��146��1),������в�ֺ�ĳ˻�֮�͵�����������һ��Lily Number��
//���磺
//655 = 6 * 55 + 65 * 
//1461 = 1*461 + 14*61 + 146*1
//��� 5λ���е����� Lily Number��
#include <stdio.h>

int Lily_Number(int i, int mul)
{
	int sum = 0;
	mul = mul / 10;
	if (mul >= 10)
	{
		sum = (i / mul) * (i - i / mul * mul) + Lily_Number(i, mul);
	}
	return sum;
}

int main()
{
	for (int i = 10000; i <= 99999; i++) // 73829
	{
		int mul = 100000;
		int sum = Lily_Number(i, mul);
		if (sum == i)
		{
			printf("%d ",i);
		}
	}
	return 0;
}