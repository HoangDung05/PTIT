#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inFile("DT.INP");
    ofstream outFile("DT.OUT");
    if (inFile.is_open())
    {
        int t, n;
        inFile >> t >> n;
        vector<vector<int>> ke(n+1);
        int mtran_ke[n+1][n+1] = {};
        for (int i = 1; i <= n; i++)
        {
            int k; 
            inFile >> k;
            for (int j = 1; j <= k; j++)
            {
                int u;
                inFile >> u;
                ke[i].push_back(u);
                mtran_ke[i][u] = 1;
            }
        }
        
        if (t == 1)
        {
            for (int i = 1; i <= n; i++)
                outFile << ke[i].size() << " ";
        }
        
        else if (t == 2)
        {
            outFile << n << endl;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                    outFile << mtran_ke[i][j] << " ";
                outFile << endl;
            }
        }
    }
    return 0;
}