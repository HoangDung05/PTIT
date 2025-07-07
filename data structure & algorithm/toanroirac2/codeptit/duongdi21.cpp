// Cho trước đồ thị G = (V, E) gồm n đỉnh biểu diễn dưới dạng ma trận kề và hai đỉnh u, v.
// Tìm số lượng đường đi độ dài 2 trên G từ đỉnh u đến v.
// Tìm đường đi trên G từ đỉnh u đến v sử dụng thuật toán tìm kiếm theo chiều sâu (DFS).

#include<bits/stdc++.h>
using namespace std;
int n, u, v;
vector<vector<int>> a;
vector<int> truoc(105, 0);
vector<bool> visited(105, false);

void DFS(int u1)
{
    visited[u1] = true;
    if (u1 == v)
        return;
    for (int i = 1; i <= n; i++)
    {
        if (a[u1][i] && !visited[i])
        {
            truoc[i] = u1;
            DFS(i);
        }
    }
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
        DFS(u);
        if (truoc[v] == 0)
            outFile << 0;
        else
        {
            int current = v;
            vector<int> path;
            while (current != 0)
            {
                path.push_back(current);
                current = truoc[current];
            }
            reverse(path.begin(), path.end());
            for (int c: path)
                outFile << c << " ";
        }
        
        
    }
    
}