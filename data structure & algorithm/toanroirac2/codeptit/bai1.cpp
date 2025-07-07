#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ke(n+1);
    vector<int> deg_ra(n+1, 0), deg_vao(n+1, 0);
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        ke[u].push_back(v);
        deg_ra[u]++;
        deg_vao[v]++;
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << deg_vao[i] << " " << deg_ra[i] << endl;
        }
    }

    else if (t == 2)
    {
        cout << n << endl;
        for (int i = 1; i <= n; i++)
        {
            sort(ke[i].begin(), ke[i].end());
            cout << ke[i].size() << " ";
            for (int c: ke[i])
                cout << c << " ";
            cout << endl;
        }
    }
}