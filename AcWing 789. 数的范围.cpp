//https://www.acwing.com/problem/content/791/
#include <iostream>
using namespace std;

const int N = 100010;
int a[N];
int n, q;

void bsleft(int k)
{
    int l = 0, r = n-1;
    while(l < r)
    {
        int mid = l + (r - l) / 2;
        if(a[mid] < k) l = mid + 1;
        else r = mid;
    }
    if(a[l] == k)
        cout << l;
    else
        cout << -1;
}

void bsright(int k)
{
    int l = 0, r = n-1;
    while(l < r)
    {
        int mid = l + (r - l + 1) / 2;
        if(a[mid] > k) r = mid - 1;
        else l = mid;
    }
    if(a[l] == k)
        cout << l;
    else
        cout << -1;
}

int main()
{
    cin >> n >> q;
    for(int i = 0;i < n;i++)
        cin >> a[i];
    for(int i = 0;i < q;i++)
    {
        int k;
        cin >> k;
        bsleft(k);
        cout << " ";
        bsright(k);
        cout << endl;
    }
    return 0;
}
