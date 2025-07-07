#include<bits/stdc++.h>
using namespace std;
int t, n, u, v;
vector<vector<int>> a(100, vector<int>(100, 0));
vector<bool> visited(100, true);
vector<int> ans;



int countPath()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (a[u][i] && a[i][v])
            ans++;
    return ans;
}

void DFS(int u)
{   
    visited[u] = false;
    ans.push_back(u);
    if (u == v)
        return;
    for (int i = 1; i <= n; i++)
        if (visited[i] && a[u][i] == 1)
            DFS(i);
}

int main()
{
    cin >> t >> n >> u >> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
        
    if (t == 1)
    {
        cout << countPath();
    }
    if (t == 2)
    {
        DFS(u);
        for (auto c: ans)
            cout << c << " ";
    }
    return 0;
}