#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> lienthong;
vector<vector<int>> a;

bool visited[105];

void DFS(int u, vector<int> &row)
{
    visited[u] = true;
    row.push_back(u + 1);
    for (int v = 0; v < n; v++)
    {
        if (a[u][v] == 1 && !visited[v])
            DFS(v, row);
    }
}

int main()
{
    ifstream inFile("TK.INP");
    ofstream outFile("TK.OUT");
    inFile >> n;
    a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> row;
            DFS(i, row);
            sort(row.begin(), row.end());
            lienthong.push_back(row);
        }   
    }

    outFile << lienthong.size() << endl;
    for (auto comp: lienthong)
    {
        for (int c: comp)
            outFile << c << " ";
        outFile << endl;
    }

    return 0;
}