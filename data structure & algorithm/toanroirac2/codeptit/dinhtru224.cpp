#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> a;
bool visited[105];

void DFS(int u)
{
    visited[u] = true;
    for (int v = 0; v < n; v++)
    {
        if (a[u][v] == 1 && !visited[v])
            DFS(v);
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

    int lienthong_real = 0;
    memset(visited, false, sizeof(visited));
    vector<int> dinhtru;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(i);
            lienthong_real++;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        int lienthong_fake = 0;
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j])
            {
                DFS(j);
                lienthong_fake++;
            }
        }
        if (lienthong_fake > lienthong_real)
        {
            dinhtru.push_back(i+1);
        }
    }

    outFile << dinhtru.size() << endl;
    if (!dinhtru.empty())
    {
        for (int c: dinhtru)
            outFile<< c << " ";
    }
    return 0;
}