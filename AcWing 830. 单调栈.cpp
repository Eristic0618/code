//https://www.acwing.com/problem/content/832/
#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> s;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(s.size() == 0)
        {
            cout << -1 << " ";
            s.push(a);
        }
        else
        {
            while(s.size() && s.top() >= a)
                s.pop();
            if(s.size() == 0)
                cout << -1 << " ";
            else
                cout << s.top() << " ";
            s.push(a);
        }
    }
    return 0;
}