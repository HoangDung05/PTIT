// Cho trước đồ thị vô hướng G = (V, E) gồm n đỉnh biểu diễn dưới dạng ma trận kề.
// Tìm các cạnh cầu của G sử dụng thuật toán tìm kiếm theo chiều sâu (BFS).

#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> a;
vector<pair<int, int>> dscanh;
bool visited[105];

void BFS(int u)
{
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
            if (a[s][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
    }
}

void BFS2(int u, int s, int t)
{
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if ((c == s && i == t) || (c == t && i == s))
                continue;
            if (a[c][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    ifstream inFile("TK.INP");
    ofstream outFile("TK.OUT");
    inFile >> n;
    a.resize(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            inFile >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i][j])
            {
                dscanh.push_back({i, j});
            }
        }
    memset(visited, false, sizeof(visited));
    int lienthong_real = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            BFS(i);
            lienthong_real++;
        }
    }

    int canhcau = 0;
    vector<pair<int, int>> ds_canhcau;

    for (auto c: dscanh)
    {
        int x = c.first, y = c.second;
        memset(visited, false, sizeof(visited));
        int lienthong_fake = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                BFS2(i, x, y);
                lienthong_fake++;
            }
        }
        if (lienthong_fake > lienthong_real)
        {
            canhcau++;
            ds_canhcau.push_back({x,y});
        }
    }
    outFile << canhcau << endl;
    for (auto c: ds_canhcau)
        outFile << c.first << " " << c.second << endl;
    return 0;
}