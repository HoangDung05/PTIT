#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inFile("DT.INP");
    ofstream outFile("DT.OUT");
    if (inFile.is_open())
    {
        int t, n, m;
        inFile >> t >> n >> m;
        vector<vector<int>> a(n+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; i++)
        {
            int u, v;
            inFile >> u >> v;
            a[u][v] = 1;
            a[v][u] = 1;
        }
        
        if (t == 1)
        {
            for (int i = 1; i <= n; i++)
            {   
                int cnt = 0;
                for (int j = 1; j <= n; j++)
                {
                    if (a[i][j])
                        cnt++;
                }
                outFile << cnt << " ";
            }
        }
        else if (t == 2)
        {
            outFile << n << endl;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    outFile << a[i][j] << " ";
                }
                outFile << endl;
            }
        }
    }
    return 0;
}