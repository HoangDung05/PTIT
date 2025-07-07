#include<bits/stdc++.h>
using namespace std;
int n;

vector<vector<int>> a;
vector<int> ke[105];
vector<bool> visited(105, false);
vector<int> truoc(105, 0);

int coutPathEqual_two(int u, int v)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[u][i] == 1 && a[i][v] == 1)
            cnt++;
    }
    return cnt;
}

void BFS(int u, int v)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        for (int c: ke[s])
        {
            if (!visited[c])
            {
                visited[c] = true;
                q.push(c);
                truoc[c] = s;
                // if (c == v)
                // return;
            }
        }
    }
    
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    int t; cin >> t;
    int u, v;
    cin >> n >> u >> v;
    a.resize(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                ke[i].push_back(j);
            }
        }
    }

    if (t == 1)
    {
        cout << coutPathEqual_two(u, v);
    }

    else if (t == 2)
    {
        vector<int> path;
        BFS(u, v);
        if (!visited[v])
            cout << 0;
        else
        {
            path.push_back(v);
            int x = truoc[v];
            while (x != u)
            {
                path.push_back(x);
                x = truoc[x];
            }
            path.push_back(u);
            reverse(path.begin(), path.end());
            for (int c: path)
                cout << c << " ";
        }
    }

    return 0;
}

// 1 3 2 4