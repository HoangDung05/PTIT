#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
int n, m;
vector<int> adj[MAX];
vector<bool> visited(MAX, false);
vector<int> ans;
queue<int> q;

void BFS(int u)
{
    q.push(u);
    visited[u] = true;
    ans.push_back(u);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto neighbor: adj[t])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
                if (find(ans.begin(), ans.end(), neighbor) == ans.end())
                    ans.push_back(neighbor);
            }
        }
    }
    
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int ui, vi;
        cin >> ui >> vi;
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }
    BFS(1);
    for (auto c: ans)
        cout << c << " ";
    return 0;
}