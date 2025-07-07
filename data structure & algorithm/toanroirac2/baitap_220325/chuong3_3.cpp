#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
int n, m, u, v;
vector<int> adj[MAX], ans;
vector<bool> visited(MAX, false);
queue<int> q;
vector<int> parent(MAX, -1); // Lưu vết đường đi 

int countPathsOfLength2()
{
    int count = 0;
    for (auto c: adj[u])
        if (find(adj[v].begin(), adj[v].end(), c) != adj[v].end())
            count++;
    return count;
}

vector<int> BFS(int u)
{
    q.push(u);
    visited[u] = true;
    // ans.push_back(u);
    while (!q.empty())
    {
        int s = q.front();
        q.pop();

        if (s == v)
            break;

        for (auto c: adj[s])
        {
            if (!visited[c])
            {
                visited[c] = true;
                parent[c] = s;
                q.push(c);
            }
        }
    }

    // Truy vết đường đi
    vector<int> path;
    if (parent[v] != -1)
    {
        int node = v;
        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
    }

    return path;
}

int main()
{
    int t; cin >> t;
    cin >> n >> m >> u >> v;
    for (int i = 1; i <= m; i++)
    {
        int ui, vi;
        cin >> ui >> vi;
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }
    if (t == 1)
    {
        cout << countPathsOfLength2();
    }
    else if (t == 2)
    {
        vector<int> path = BFS(u);
        if (path.empty())
            cout << 0;
        else
            for (auto c: path)
                cout << c << " ";
    }
    return 0;
}