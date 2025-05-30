// Cho trước đồ thị G = (V, E) gồm n đỉnh biểu diễn dưới dạng ma trận kề và hai đỉnh u, v.
// Tìm số lượng đường đi độ dài 2 trên G từ đỉnh u đến v.
// Tìm đường đi trên G từ đỉnh u đến v sử dụng thuật toán tìm kiếm theo chiều sâu (BFS).

#include<bits/stdc++.h>
using namespace std;
int n, u, v;
vector<vector<int>> a;

vector<int> BFS(int u1)
{
    vector<int> truoc(n+1, 0);
    vector<bool> visited(n+1, false);

    queue<int> q;
    q.push(u1);
    visited[u1] = true;
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        if (s == v)
            break;
        for (int i = 1; i <= n; i++)
        {
            if (a[s][i] && !visited[i])
            {
                q.push(i);
                truoc[i] = s;
                visited[i] = true;
            }
        }
    }

    int current = v;
    vector<int> path;
    if (truoc[v] == 0)
        return path;
    while (current != 0)
    {
        path.push_back(current);
        current = truoc[current];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ifstream inFile("TK.INP");
    ofstream outFile("TK.OUT");
    int t; inFile >> t;
    inFile >> n >> u >> v;
    a.resize(n + 1, vector<int>(n+1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            inFile >> a[i][j];

    if (t == 1)
    {   
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[u][i] && a[i][v])
                cnt++;
        }
        outFile << cnt;
    }

    else if (t == 2)
    {
        vector<int> path = BFS(u);
        if (path.empty())
            outFile << 0;
        else    
        {
            for (int node: path)
                outFile << node << " ";
        }
    }
    
}