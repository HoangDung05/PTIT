#include<bits/stdc++.h>
using namespace std;

void BFS(int u, vector<bool> &visited, const vector<vector<int>> &list)
{
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int s = q.front(); q.pop();
        visited[s] = true;
        cout << s << " ";
        for (int c: list[s])
        {
            if (!visited[c])
            {
                visited[c] = true;
                q.push(c);
            }
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
        BFS(u, visited, list);
        cout << endl;
    }
    
    return 0;
}