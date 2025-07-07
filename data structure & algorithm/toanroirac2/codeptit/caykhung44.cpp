#include<bits/stdc++.h>
using namespace std;
#define iii tuple<int, int, int>

struct edge {
    int x, y, w;
};

int n, s, parent[105], d[105];
vector<pair<int, int>> ke[105];
bool used[105];

void Prim(int u)
{
    priority_queue<iii, vector<iii>, greater<iii>> q;
    vector<edge> mst;
    int res = 0;

    fill(d+1, d+n+1, 1e9);
    fill(parent+1, parent+n+1, -1);

    d[u] = 0;
    q.push({0, -1, u});

    while (!q.empty())
    {
        auto [w, x, y] = q.top();
        q.pop();
        if (used[y])
            continue;
        
        used[y] = true;
        res += w;
        if (x != -1)
            mst.push_back({x, y, w});
        
        for (auto [v, w2]: ke[y])
        {
            if (!used[v] && w2 < d[v])
            {
                d[v] = w2;
                parent[v] = y;
                q.push({w2, y, v});
            }
        }
    }

    if (mst.size() < n-1)
    {
        cout << 0;
        return;
    }
    cout << res << endl;
    for (auto [x, y, w]: mst)
    {
        cout << min(x, y) << " " << max(x, y) << " " << w << endl;
    }
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x; cin >> x;
            if (i != j && x < 10000)
                ke[i].push_back({j, x});
        }
    }
    Prim(s);
    return 0;
}