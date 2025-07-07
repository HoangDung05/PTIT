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
        vector<vector<int>> ke(n+1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            inFile >> u >> v;
            ke[u].push_back(v);
            ke[v].push_back(u);
        }
        
        if (t == 1)
        {
            for (int i = 1; i <= n; i++)
            {   
                outFile << ke[i].size() << " ";
            }
        }
        else if (t == 2)
        {
            outFile << n << endl;
            for (int i = 1; i <= n; i++)
            {
                outFile << ke[i].size() << " ";
                for (int c: ke[i])
                    outFile << c << " ";
                outFile << endl;
            }
        }
    }
    return 0;
}