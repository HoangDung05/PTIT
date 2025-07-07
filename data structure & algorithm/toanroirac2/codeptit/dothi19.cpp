#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> lienthuoc;
vector<pair<int,int>> edge;
int deg[105];


int main()
{
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);
    int t; cin >> t;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        deg[i] = k;
        for (int j = 1; j <= k; j++)
        {
            int x; cin >> x;
            if (x > i)
                edge.push_back({i, x});
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
        lienthuoc.resize(n+1, vector<int>(edge.size()+1, 0));
        for (int i = 0; i < edge.size(); i++)
        {
            lienthuoc[edge[i].first][i+1] = 1;
            lienthuoc[edge[i].second][i+1] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= edge.size(); j++)
                cout << lienthuoc[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}