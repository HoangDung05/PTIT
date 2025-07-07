#include<bits/stdc++.h>
using namespace std;

//Cach 1: de quy
void BFS(const vector<vector<int>> &list, int u, vector<bool> &visited){
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
        int V, E, cnt = 0;
        cin >> V >> E;
        //1. bieu dien do thi duoi dang danh sach ke
        vector<vector<int>> list(V+1); 
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            if (u < 1 || u > V || v < 1 || v > V) {
                continue;  // Bỏ qua cạnh không hợp lệ
            }
            list[u].push_back(v);
            list[v].push_back(u);
        }

        vector<bool> visited(V+1, false);
        for (int i = 1; i <= V; i++)
        {
            if(!visited[i])
            {
                BFS(list, i, visited);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}