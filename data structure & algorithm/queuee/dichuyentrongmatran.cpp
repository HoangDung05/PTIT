#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int m, n; cin >> m >> n;
        int a[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        // mảng kc: dist[i][j] là số bước nhỏ nhất để đến ô (i,j)
        vector<vector<int>> dist(m, vector<int>(n, -1));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        // bắt đầu từ (1,1) trong bài toán -> (0,0) trong mảng
        q.push({0, 0});
        dist[0][0] = 0;
        visited[0][0] = true;
        while (!q.empty())
        {
            pair<int, int> x = q.front();
            q.pop();
            int i = x.first, j = x.second;

            // nhảy sang phải (i, j+a[i][j])
            int nj = j + a[i][j];
            if (nj < n && !visited[i][nj]) // kiểm tra chỉ số hợp lệ
            {
                visited[i][nj] = true;
                dist[i][nj] = dist[i][j] + 1;
                q.push({i, nj});
            }
            
            // nhảy sang trái (i + a[i][j], j)
            int ni = i + a[i][j];
            if (ni < m && !visited[ni][j])
            {
                visited[ni][j] = true;
                dist[ni][j] = dist[i][j] + 1;
                q.push({ni, j});
            }
        }
        // kq: dist[m-1][n-1] là số bước đến (m, n)
        cout << dist[m-1][n-1] << endl;
    }
    return 0;
}