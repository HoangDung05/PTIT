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

void DFS1(int u)
{
    visited[u] = true;
    for (int v = 0; v < n; v++)
    {
        if ((a[u][v] == 1 || a[v][u] == 1) && !visited[v])
            DFS1(v);
    }
}

bool isStronglyConnected()
{
    for (int i = 0; i < n; i++)
    {
        memset(visited, false, sizeof(visited));
        DFS(i);
        for (int j = 0; j < n; j++)
            if (!visited[j])
                return false;
    }
    return true;
}

bool isWeaklyConnected()
{
    memset(visited, false, sizeof(visited));
    DFS1(0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            return false; 
    }
    return true;
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

    if (isStronglyConnected())
        outFile << 1;
    else if (isWeaklyConnected())
        outFile << 2;
    else 
        outFile << 0;

    inFile.close();
    outFile.close();
    return 0;
}