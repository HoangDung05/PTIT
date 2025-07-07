// bieu dien do thi: ds canh -> ds ke
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> list(V+1);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }

    for (int u = 1; u <= V; u++)
    {
        cout <<"Danh sach ke cua dinh " << u << ": ";
        for (int x: list[u])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}