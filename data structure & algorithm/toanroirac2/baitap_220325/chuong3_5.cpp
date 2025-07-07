#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
int n;
vector<vector<int>> adj(MAX, vector<int>(MAX, 0));
vector<bool> visited(MAX, false);
vector<int> saveTop;
vector<int> save[MAX];
queue<int> q;

void BFS(int u)
{
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        if (find(saveTop.begin(), saveTop.end(), t) == saveTop.end())
            saveTop.push_back(t);
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && adj[t][i])
            {
                BFS(i);
            }
        }
    }
    
}

int countTplt()
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            count++;
            BFS(i);
            save[count] = saveTop;
            saveTop.clear();
        }
    }
    return count;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> adj[i][j];
    int count = countTplt();
    cout << count << endl;
    for (int i = 1; i <= count; i++)
    {
        for (auto c: save[i])
            cout << c << " ";
        cout << endl;
    }
    return 0;
}