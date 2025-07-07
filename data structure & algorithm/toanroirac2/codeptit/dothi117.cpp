#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> edge;
vector<vector<int>> lienthuoc;
vector<int> ke[105];
vector<int> deg_ra(1000), deg_vao(1000);

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    

    int t, n, m; cin >> t >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int dau, cuoi;
        cin >> dau >> cuoi;
        deg_ra[dau]++;
        deg_vao[cuoi]++;
        edge.push_back({dau, cuoi});
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
            cout << deg_vao[i] << " " << deg_ra[i] << endl;
    }

    else if (t == 2)
    {
        cout << n << " " << m << endl;
        lienthuoc.resize(n+1, vector<int>(m+1, 0));
        for (int i = 0; i < edge.size(); i++)
        {
            lienthuoc[edge[i].first][i+1] = 1;
            lienthuoc[edge[i].second][i+1] = -1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << lienthuoc[i][j] << " ";
            cout << endl;
        }

    }
    return 0;
}