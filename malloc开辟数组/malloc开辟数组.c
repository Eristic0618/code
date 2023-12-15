//使用malloc函数模拟开辟一个3*5的整型二维数组，开辟好后，使用二维数组的下标访问形式，访问空间
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