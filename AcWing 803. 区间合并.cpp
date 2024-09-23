// https://www.acwing.com/problem/content/805/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> seg;

void merge()
{
    vector<pair<int, int>> tmp;
    sort(seg.begin(), seg.end());
    int st = seg[0].first, ed = seg[0].second;
    for (int i = 1; i < seg.size(); i++)
    {
        if (ed < seg[i].first)
        {
            tmp.push_back({st, ed});
            st = seg[i].first;
            ed = seg[i].second;
        }
        else
            ed = max(ed, seg[i].second);
    }
    tmp.push_back({st, ed});
    seg = tmp;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        seg.push_back({a, b});
    }
    if (seg.size())
        merge();

    cout << seg.size() << endl;
}