#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> ke[105];
vector<bool> visited(105, false);
vector<pair<int, int>> edge_tree;

void Tree_DFS(int u)
{
    visited[u] = true;
    for (auto c: ke[u])
    {
        if (!visited[c])
        {
            edge_tree.push_back({u, c});
            Tree_DFS(c);
        }
    }
}

void Tree_BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        for (auto c: ke[s])
        {
            if (!visited[c])
            {
                visited[c] = true;
                q.push(c);
                edge_tree.push_back({s, c});
            }
        }
    }
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    int t; cin >> t;
    int s;  
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x; cin >> x;
            if (x == 1)
                ke[i].push_back(j);
        }
    }

    if (t == 1)
        Tree_DFS(s);
    else
        Tree_BFS(s);

    if (edge_tree.size() != n - 1)
        cout << 0;
    else
    {
        cout << n - 1 << endl;
        for (auto [x, y]: edge_tree)
        {
            if (x > y)
                swap(x, y);
            cout << x << " " << y << endl;
        }
    }
    return 0;
}