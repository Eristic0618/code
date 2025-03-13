//https://www.acwing.com/activity/content/problem/content/819/
#include <iostream>
using namespace std;

#define N 100010

int n;
int a[N];

void quick_sort(int* a, int l, int r)
{   
    if(l == r)
        return;
    int i = l-1, j = r+1, k = a[l + r >> 1];
    while(i < j)
    {
        do i++; while(a[i] < k);
        do j--; while(a[j] > k);
        if(i < j) swap(a[i], a[j]);
    }
    quick_sort(a, l, j), quick_sort(a, j+1, r);
}

int main()
{
    cin >> n;
    for(int i = 0 ;i < n; i++)
    {
        cin >> a[i];
    }
    quick_sort(a, 0, n-1);
    for(int i = 0 ;i < n; i++)
    {
        cout << a[i] << " ";
    }
}