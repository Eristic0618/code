// https://leetcode.cn/problems/master-mind-lcci/
// ����������Ϸ��the game of master mind�����淨���¡�
// �������4���ۣ�ÿ���۷�һ������ɫ�����Ǻ�ɫ��R������ɫ��Y������ɫ��G������ɫ��B����
// ���磬�����������RGGB 4�֣���1Ϊ��ɫ����2��3Ϊ��ɫ����4Ϊ��ɫ������Ϊ�û�������ͼ�³���ɫ��ϡ�
// ����ȷ�������ܻ��YRGB��Ҫ�ǲ¶�ĳ���۵���ɫ������һ�Ρ����С���Ҫ��ֻ�¶���ɫ����λ�´��ˣ�����һ�Ρ�α���С���
// ע�⣬�����С��������롰α���С���
// ����һ����ɫ���solution��һ���²�guess����дһ�����������ز��к�α���еĴ���answer
// ����answer[0]Ϊ���еĴ�����answer[1]Ϊα���еĴ���
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