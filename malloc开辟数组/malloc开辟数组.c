//ʹ��malloc����ģ�⿪��һ��3*5�����Ͷ�ά���飬���ٺú�ʹ�ö�ά������±������ʽ�����ʿռ�
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int(*arr)[5] = (int(*)[5])malloc(sizeof(int[5]) * 3);
	for (int i = 0; i < 3;i++)
	{
		for (int j = 0; j < 5;j++)
		{
			arr[i][j] = j;
		}
	}
	for (int i = 0; i < 3;i++)
	{
		for (int j = 0; j < 5;j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	free(arr);
	arr = NULL;
	return 0;
}