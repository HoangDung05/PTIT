#include<bits/stdc++.h>
using namespace std;

//Cach 1: de quy
void DFS(vector<vector<int>> list, int u, vector<bool> &visited){
    // visited[u] = true;
    // cout << u << " ";
    // for (int v: list[u])
    // {
    //     if (!visited[v])
    //     {
    //         DFS(list, v, visited);
    //     }       
    // }

}




int main()
{
    int t; cin >> t;
    while (t--)
    {
        int V, E, u;
        cin >> V >> E >> u;
        vector<vector<int>> list(V+1); //bieu dien do thi duoi dang danh sach ke
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            list[u].push_back(v);
            list[v].push_back(u);
        }

        vector<bool> visited(V+1, false);
        DFS(list, u, visited);
        cout << endl;
    }
    return 0;
}