//�ڵ�ǰĿ¼�·�һ���ļ�data.txt����data.txt�ļ�����һ�ݣ�����data_copy.txt�ļ�
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