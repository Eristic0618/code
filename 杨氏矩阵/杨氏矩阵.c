// ��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ����
// Ҫ��ʱ�临�Ӷ�С��O(N)
#include <stdio.h>

int main()
{
    int arr[3][5] = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}};
    int xright = 4;
    int yup = 0;
    int num = 0;
    printf("��������Ҫ���ҵ�����:>");
    scanf("%d", &num);
    int flag = 0;
    while (1)
    {
        if (xright < 0 || yup > 2)
        {
            printf("Ŀ�겻����\n");
            break;
        }
        else if (arr[yup][xright] > num)
        {
            xright--;
        }
        else if (arr[yup][xright] < num)
        {
            yup++;
        }
        else if (arr[yup][xright] == num)
        {
            printf("Ŀ�����\n");
            break;
        }
    }
    return 0;
}