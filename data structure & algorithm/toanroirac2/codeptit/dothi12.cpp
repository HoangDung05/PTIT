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
        vector<vector<int>> a;
        string line;
        
        while (getline(inFile, line))
        {
            stringstream ss(line);
            vector<int> row;
            int num;
            while (ss >> num)
            {
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
            outFile << n << endl;
            vector<int> ke;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (a[i][j])
                        ke.push_back(j+1);
                }
                outFile << ke.size() << " ";
                for (int c: ke)
                    outFile << c << " ";
                outFile << endl;
                ke.clear();
            }
        }
    }
}