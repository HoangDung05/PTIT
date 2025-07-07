// Cho trước đồ thị vô hướng G = (V, E) gồm n đỉnh biểu diễn dưới dạng ma trận kề.
// Tìm các cạnh cầu của G sử dụng thuật toán tìm kiếm theo chiều sâu (DFS).

#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> a;
vector<pair<int, int>> dscanh;
bool visited[105];

void DFS(int u)
{
    visited[u] = true;
    for (int i = 1; i <= n; i++)
        if (a[u][i] && !visited[i])
            DFS(i);
}

void DFS2(int u, int s, int t)
{
    visited[u] = true;
    for (int i = 1; i <= n; i++)
    {
        if ((u == s && i == t) || (u == t && i == s))
            continue;
        if (a[u][i] && !visited[i])
            DFS2(i, s, t);
    }
}

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");
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
            DFS(i);
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
                DFS2(i, x, y);
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