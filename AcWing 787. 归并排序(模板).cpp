//https://www.acwing.com/problem/content/789/
#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n;
int a[N];

void merge_sort(int a[], int l, int r, int tmp[])
{
    if(l == r)
        return;
    int mid = (l+r) >> 1;
    merge_sort(a, l, mid, tmp), merge_sort(a, mid+1, r, tmp);
    int k = 0, i = l, j = mid+1;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(int k = 0, i = l; i <= r; i++, k++)
        a[i] = tmp[k];
}

int main()
{
    cin >> n;
    for(int i = 0;i < n; i++)
        cin >> a[i];
    int* tmp = (int*)malloc(sizeof(int) * n);
    merge_sort(a, 0, n-1, tmp);
    for(int i = 0;i < n; i++)
        cout << a[i] << " ";
    return 0;
}