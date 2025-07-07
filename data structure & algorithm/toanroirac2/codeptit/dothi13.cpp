#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inFile("DT.INP");
    ofstream outFile("DT.OUT");
    if (inFile.is_open())
    {
        int t, n, bac = 0;
        inFile >> t >> n;
        string line;
        vector<vector<int>> a;
        while (getline(inFile, line))
        {   
            stringstream ss(line);
            int num;
            vector<int> row;
            while (ss >> num)
            {
                if (num)
                    bac++;
                row.push_back(num);    
            }
            if (!row.empty())
                a.push_back(row);
        }
        
        if (t == 1)
        {
            for (int i = 0; i < n; i++)
            {   
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    if (a[i][j])
                        cnt++;
                }
                outFile << cnt << " ";
            }
        }
        else if (t == 2)
        {
            int edge = bac/2;
            int edge_index = 0;
            vector<vector<int>> lienthuoc(n, vector<int>(edge, 0));
            outFile << n << " " << edge << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (a[i][j])
                    {
                        lienthuoc[i][edge_index] = 1;
                        lienthuoc[j][edge_index] = 1;
                        edge_index++;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < edge; j++)
                {
                    outFile << lienthuoc[i][j] << " ";
                }
                outFile << endl;
            }
        }
    }
    return 0;
}