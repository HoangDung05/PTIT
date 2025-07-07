#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> a;
vector<tuple<int,int, int>> edge;
int deg[105];


int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t; cin >> t;
    cin >> n;
    a.resize(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] > 0 && a[i][j] <= 50)
            {
                deg[i]++;
                if (j > i)
                    edge.push_back({i, j, a[i][j]});
            }     
        }
    }
    
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
            cout << deg[i] << " ";
    }

    else if (t == 2)
    {

        cout << n << " " << edge.size() << endl;
        for (auto [x, y, z]: edge)
            cout << x << " " << y << " " << z << endl;
    }
    return 0;
}