#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    int n, m; cin >> n >> m;
    map<int, int> mp;
    int a[n][n];
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = 0;
            }
        }
    for (int i = 0; i < m; i++)
    {
        int b; int c;
        cin >> b >> c;
        mp[b]++;
        mp[c]++;
        a[b-1][c-1] = 1;
        a[c-1][b-1] = 1;
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
            cout << mp[i] << " ";
    }

    else if (t == 2)
    {
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}