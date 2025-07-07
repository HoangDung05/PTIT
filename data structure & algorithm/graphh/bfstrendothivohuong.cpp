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
        cout << x << " ";
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
        int V, E, u;
        cin >> V >> E >> u;
        //1. bieu dien do thi duoi dang danh sach ke
        vector<vector<int>> list(V+1); 
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        for (int i = 1; i <= V; i++)
        {
            sort(list[i].begin(), list[i].end());
        }

        vector<bool> visited(V+1, false);
        BFS(list, u, visited);
        cout << endl;
    }
    return 0;
}