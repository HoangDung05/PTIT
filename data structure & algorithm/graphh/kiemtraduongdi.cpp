#include<bits/stdc++.h>
using namespace std;

//Cach 1: de quy
void BFS(vector<vector<int>> list, int u, vector<bool> &visited){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int v: list[x])
        {

            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }   
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        //1. bieu dien do thi duoi dang danh sach ke
        vector<vector<int>> list(V+1); 
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        
        int Q; cin >> Q;
        while (Q--)
        {
            int u, v;
            cin >> u >> v;
            vector<bool> visited(V+1, false);
            BFS(list, u, visited);
            if (visited[v])
                cout << "YES\n";
            else   
                cout << "NO\n";
        }
    }
    return 0;
}