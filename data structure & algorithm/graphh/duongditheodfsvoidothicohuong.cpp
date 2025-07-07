#include<bits/stdc++.h>
using namespace std;
bool check = false;

void DFS(int u, int v, vector<bool> &visited, const vector<vector<int>> &list, int truoc[])
{
    stack<int> st;
    st.push(u);
    visited[u] = true;
    while (!st.empty())
    {
        int s = st.top();
        st.pop();
        if (s == v)
        {
            check = true;
            return;
        }
        for (int c: list[s])
        {
            if (!visited[c])
            {
                truoc[c] = s;
                visited[c] = true;
                st.push(s);
                st.push(c);
                break;
            }
        }
    }
    
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        check = false;
        int dinh, e, u, v;
        cin >> dinh >> e >> u >> v;
        int truoc[dinh+1] = {};
        vector<int> path;
        vector<vector<int>> list(dinh+1);
        vector<bool> visited(dinh+1, false);
        for (int i = 1; i <= e; i++)
        {
            int dau, cuoi;
            cin >> dau >> cuoi;
            list[dau].push_back(cuoi);
        }
        DFS(u, v, visited, list, truoc);
        if (check == false)
            cout << -1;
        else
        {
            while (truoc[v] != 0)
            { 
                path.push_back(v);
                v = truoc[v];
            }
            path.push_back(u);
            for (int i = path.size() - 1; i >= 0; i--)
                cout << path[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}