#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

vector<int> adj[MAX]; //Danh sách kề
vector<bool> visited(MAX, true);
vector<int> ans;
int t, n, m, u, v;
int check = 0;

// (1) Tìm số lượng đường đi độ dài 2 từ u đến v
int countPathsOfLength2(int n, int u, int v)
{
    int count = 0;
    for (int neighbor: adj[u])
        if (find(adj[neighbor].begin(), adj[neighbor].end(), v) != adj[neighbor].end())
            count++;
    return count;
}

// (2) Tìm đường đi từ u đến v bằng DFS
void DFS(int u)
{
    visited[u] = false;
    ans.push_back(u);
    if (u == v) 
    {
        check = 1;
        return;
    }
        
    else
        for (auto neighbor: adj[u])
            if (visited[neighbor])
                DFS(neighbor);
}

int main()
{
    cin >> t >> n >> m >> u >> v;

    // Xây dựng danh sách kề từ danh sách cạnh
    for (int i = 0; i < m; i++)
    {
        int ui, vi;
        cin >> ui >> vi;
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }

    if (t == 1)
    {
        cout << countPathsOfLength2(n, u, v);
    }
    else if (t == 2)
    {
        DFS(u);
        if (check)
            for (auto c: ans)
                cout << c << " ";
        else
            cout << 0;
    }
}