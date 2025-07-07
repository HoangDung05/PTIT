#include<bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
int n, s, t, par[1005], a[1005][1005];
vector<ii> adj[1005];

int main()
{
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] && a[i][j] <= 50)
                adj[i].push_back({ j, a[i][j] });
        }
    }

    vector<int> d(n + 1, 1e9);
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({ 0, s });
    d[s] = 0;
    par[s] = s;

    while (!q.empty())
    {
        auto [dis, u] = q.top();
        q.pop();

        if (dis > d[u])
            continue;
        
        for (auto [v, w]: adj[u])
        {
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({ d[v], v });
                par[v] = u;
            }
        }
    }

    if (d[t] == 1e9)
        cout << 0 << endl;
    else
    {
        cout << d[t] << endl;
        vector<int> path;
        while (t != par[t])
        {
            path.push_back(t);
            t = par[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (int x: path)
            cout << x << " ";
    }
    
    return 0;
}