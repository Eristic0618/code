// https://www.acwing.com/problem/content/description/1231/
// 小明正在整理一批历史文献。这些历史文献中出现了很多日期。
// 小明知道这些日期都在1960年1月1日至2059年12月31日。
// 令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。
// 更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。
// 比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。
// 给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？
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