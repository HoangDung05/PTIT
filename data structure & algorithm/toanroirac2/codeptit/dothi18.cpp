#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> a;
vector<pair<int,int>> edge;
int deg[105];


int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t; cin >> t;
    cin >> n;
    a.resize(n+1, vector<int> (n+1));
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
        for (auto c: edge)
            cout << c.first << " " << c.second << endl;
    }

    return 0;
}