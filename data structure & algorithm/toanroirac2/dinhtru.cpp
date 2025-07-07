 #include<bits/stdc++.h>
using namespace std;
int n;
int a[105][105];
bool visited[105];

void DFS(int u)
{
    visited[u] = true;
    for(int v = 1; v <= n; v++)
    {
        if (a[u][v] && !visited[v])
        {
            DFS(v);
        }
    }
}

int ktra()
{
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            DFS(i);
        }
    }
    return cnt;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    int ans = ktra();
    vector<int> v;

    for (int u = 1; u <= n; u++)
    {
        memset(visited, false, sizeof(visited));
        visited[u] = true;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                cnt++;
                DFS(i);
            }
        }
        if(cnt > ans)
        {
            v.push_back(u);
        }
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    return 0;
}