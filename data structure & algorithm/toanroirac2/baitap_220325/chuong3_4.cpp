#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
vector<vector<int>> adj(MAX, vector<int>(MAX, 0));
vector<bool> visited(MAX, false);
stack<int> s;
vector<int> save[MAX];
vector<int> saveTop;
int n;

void DFS(int u)
{
    visited[u] = true;
    s.push(u);
    while (!s.empty())
    {
        int t = s.top();
        s.pop();
        if (find(saveTop.begin(), saveTop.end(), t) == saveTop.end())
                saveTop.push_back(t);
        for (int i = 1; i <= n; i++)
        if (!visited[i] && adj[t][i])
        {
            DFS(i);
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
            DFS(i);
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