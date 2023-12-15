//在当前目录下放一个文件data.txt，将data.txt文件拷贝一份，生成data_copy.txt文件
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *pfread = fopen("data.txt", "r");
	if (pfread == NULL)
	{
		perror("fopen->data.txt");
		return 1;
	}
	FILE *pfwrite = fopen("data_copy.txt", "w");
	if (pfwrite == NULL)
	{
		fclose(pfread);
		pfread = NULL;
		perror("fopen->data_copy.txt");
		return 1;
	}
	int ch = 0;
	while ((ch = fgetc(pfread)) != EOF)
	{
		fputc(ch, pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;
	fclose(pfread);
	pfread = NULL;
	return 0;
}