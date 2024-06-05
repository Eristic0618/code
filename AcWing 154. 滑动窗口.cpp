//https://www.acwing.com/video/65/
#include <iostream>
using namespace std;

const int N = 1000010;

int n, k;
int a[N];
int q[N];

void winmax()
{
    int h = 1, t = 0;
    for(int i = 1;i <= n;i++)
    {
        while(h <= t && a[q[t]] <= a[i])
            t--;
        q[++t] = i;
        if(q[h] < i - k + 1) h++;
        if(i >= k) cout << a[q[h]] << " ";
    }
    cout << endl;
}

void winmin()
{
    int h = 1, t = 0;
    for(int i = 1;i <= n;i++)
    {
        while(h <= t && a[q[t]] >= a[i])
            t--;
        q[++t] = i;
        if(q[h] < i - k + 1) h++;
        if(i >= k) cout << a[q[h]] << " ";
    }
    cout << endl;
}

int main()
{
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    winmin();
    winmax();
    return 0;
}