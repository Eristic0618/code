//��һ���������У��������ظ�������������ɾ��ָ����ĳһ�����������ɾ��ָ������֮������У�������δ��ɾ�����ֵ�ǰ��λ��û�з����ı䡣
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int num1;
	scanf("%d", &num1);
	int num2 = num1;
	int* parr = NULL;
	parr = (int*)malloc(sizeof(int) * num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", parr + i);
	}
	int tar;
	scanf("%d", &tar);
	for (int j = 0; j < num2; j++)
	{
		if (*(parr + j) == tar)
		{
			for (int x = 0; x < num1 - j - 1; x++)
			{
				*(parr + j + x) = *(parr + j + x + 1);
			}
			num2--;
			j--;
		}
	}
	for (int i = 0; i < num2; i++)
	{
		printf("%d ", *(parr + i));
	}
	return 0;
}