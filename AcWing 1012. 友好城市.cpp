//https://www.acwing.com/problem/content/1014/
#include <bits/stdc++.h>
using namespace std;

#define N 5050

template<class T>
class cmp{
public:    
    bool operator()(const T& a, const T& b)
    {
        return a.first < b.first;
    }
};

int n, res;
int f[N];
vector<pair<int, int>> v;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp<pair<int,int>>()); //以北岸城市坐标为标准升序排序
    for(int i = 0; i < n; i++) //计算南岸城市的LIS
    {
        f[i] = 1;
        for(int j = 0; j < i; j++)
            if(v[i].second > v[j].second)
                f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }
    cout << res << endl;
    return 0;
}