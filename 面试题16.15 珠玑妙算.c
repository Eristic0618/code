// https://leetcode.cn/problems/master-mind-lcci/
// 珠玑妙算游戏（the game of master mind）的玩法如下。
// 计算机有4个槽，每个槽放一个球，颜色可能是红色（R）、黄色（Y）、绿色（G）或蓝色（B）。
// 例如，计算机可能有RGGB 4种（槽1为红色，槽2、3为绿色，槽4为蓝色）。作为用户，你试图猜出颜色组合。
// 打个比方，你可能会猜YRGB。要是猜对某个槽的颜色，则算一次“猜中”；要是只猜对颜色但槽位猜错了，则算一次“伪猜中”。
// 注意，“猜中”不能算入“伪猜中”。
// 给定一种颜色组合solution和一个猜测guess，编写一个方法，返回猜中和伪猜中的次数answer
// 其中answer[0]为猜中的次数，answer[1]为伪猜中的次数
int *masterMind(char *solution, char *guess, int *returnSize)
{
    int *ret = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    char *hash[2][4] = {0};
    int x = 0;
    for (int i = 0; i < 4; i++)
    {
        hash[0][x++] = *(solution + i);
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (hash[0][j] == *(guess + i) && hash[1][j] == 0)
            {
                hash[1][j]++;
                break;
            }
        }
    }
    int real = 0, fake = 0;
    for (int i = 0; i < 4; i++)
    {
        if (hash[1][i] != 0)
        {
            fake++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j && *(solution + i) == *(guess + j))
            {
                real++;
            }
        }
    }
    ret[0] = real;
    ret[1] = fake - real;
    return ret;
}