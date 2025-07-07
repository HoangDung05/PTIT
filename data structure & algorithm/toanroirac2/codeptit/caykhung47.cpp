#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<tuple<int, int, int>> ke;
int par[105], sz[105];

int find(int u)
{
    if (u == par[u])
        return u;
    return par[u] = find(par[u]);
}

bool Union(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (u > v)
        swap(u, v); 
    sz[u] += sz[v];
    par[v] = u;
    return true;
}

void Kruskal()
{
    vector<tuple<int,int,int>> mst;
    int res = 0;

    sort(ke.begin(), ke.end());

    for (auto [w, x, y]: ke)
    {
        if (mst.size() == n-1)
            break;
        if (Union(x, y))
        {
            res += w;
            mst.push_back({x, y, w});
        }
    }

    if (mst.size() < n-1)
    {
        cout << 0;
        return;
    }

    cout << res << endl;
    for (auto [x, y, w]: mst)
        cout << x << " " << y << " " << w << endl;
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        ke.push_back({w, x, y});
    }

    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
    Kruskal();
    return 0;
}