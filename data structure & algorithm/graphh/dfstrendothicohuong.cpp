#include<bits/stdc++.h>
using namespace std;

void DFS(int u, vector<bool> &visited, const vector<vector<int>> &list)
{
    cout << u << " ";
    visited[u] = true;
    for (int c: list[u])
    {
        if (!visited[c])
        {
            DFS(c, visited, list);
        }
    }
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int v, e, u;
        cin >> v >> e >> u;
        vector<vector<int>> list(v+1);
        vector<bool> visited(v+1, false);
        for (int i = 1; i <= e; i++)
        {
            int dau, cuoi;
            cin >> dau >> cuoi;
            list[dau].push_back(cuoi);
        }
        DFS(u, visited, list);
        cout << endl;
    }
    
    return 0;
}