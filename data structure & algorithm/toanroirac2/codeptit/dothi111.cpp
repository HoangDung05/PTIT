#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> a;
vector<tuple<int,int, int>> edge;
int deg[105];


int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t; cin >> t;
    cin >> n >> m;
    a.resize(n+1, vector<int>(n+1, 10000));
    for (int i = 1; i <= m; i++)
    {
        int dau, cuoi, trongso;
        cin >> dau >> cuoi >> trongso;
        a[dau][cuoi] = trongso;
        a[cuoi][dau] = trongso;
        deg[dau]++;
        deg[cuoi]++;
    }

    for (int i = 1; i <= n; i++)
        a[i][i] = 0;
    
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
            cout << deg[i] << " ";
    }

    else if (t == 2)
    {

        cout << n << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}