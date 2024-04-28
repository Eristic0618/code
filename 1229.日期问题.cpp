// https://www.acwing.com/problem/content/description/1231/
// С����������һ����ʷ���ס���Щ��ʷ�����г����˺ܶ����ڡ�
// С��֪����Щ���ڶ���1960��1��1����2059��12��31�ա�
// ��С��ͷ�۵��ǣ���Щ���ڲ��õĸ�ʽ�ǳ���ͳһ���в�����/��/�յģ��в�����/��/��ģ����в�����/��/��ġ�
// �����鷳���ǣ����Ҳ��ʡ����ǰ��λ��ʹ�������ϵ�һ�����ڣ����ںܶ���ܵ����������Ӧ��
// ����02/03/04��������2002��03��04�ա�2004��02��03�ջ�2004��03��02�ա�
// ����һ�������ϵ����ڣ����ܰ���С���ж�����Щ���ܵ����ڶ����Ӧ��
#include <bits/stdc++.h>
using namespace std;

int judge_year(int year)
{
    if (year >= 60)
        year += 1900;
    else
        year += 2000;
    return year;
}

vector<int> &cmp_date(int d1, int d2, int d3, vector<int> &rank)
{
    rank.push_back(d1);
    rank.push_back(d2);
    rank.push_back(d3);
    sort(rank.begin(), rank.end());
    return rank;
}

int get_month_day(int year, int month)
{
    vector<int> monthday = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        monthday[2] = 29;
    }
    return monthday[month];
}

int main()
{
    int n1, n2, n3;
    scanf("%d/%d/%d", &n1, &n2, &n3);
    int daysum1 = judge_year(n1) * 10000 + n2 * 100 + n3;
    int daysum2 = judge_year(n3) * 10000 + n1 * 100 + n2;
    int daysum3 = judge_year(n3) * 10000 + n2 * 100 + n1;
    vector<int> rank;
    cmp_date(daysum1, daysum2, daysum3, rank);
    vector<int> hash;
    for (auto i : rank)
    {
        vector<int>::iterator pos = find(hash.begin(), hash.end(), i);
        if (pos == hash.end())
        {
            hash.push_back(i);
        }
    }
    for (int i = 0; i < hash.size(); ++i)
    {
        if (daysum1 == daysum2 && daysum2 == daysum3)
        {
            printf("%d-%02d-%02d\n", judge_year(n1), n2, n3);
            break;
        }
        if (hash[i] == daysum1 && n2 >= 0 && n2 <= 12 && n3 >= 0 && n3 <= get_month_day(judge_year(n1), n2))
        {
            printf("%d-%02d-%02d\n", judge_year(n1), n2, n3);
        }
        else if (hash[i] == daysum2 && n1 > 0 && n1 <= 12 && n2 > 0 && n2 <= get_month_day(judge_year(n3), n1))
        {
            printf("%d-%02d-%02d\n", judge_year(n3), n1, n2);
        }
        else if (hash[i] == daysum3 && n2 > 0 && n2 <= 12 && n1 > 0 && n1 <= get_month_day(judge_year(n3), n2))
        {
            printf("%d-%02d-%02d\n", judge_year(n3), n2, n1);
        }
    }
}