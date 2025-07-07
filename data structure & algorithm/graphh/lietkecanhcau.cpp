#include<bits/stdc++.h>
using namespace std;

void DFS(int u, const vector<vector<int>> &list, vector<bool> &visited, int x, int y)
{
    stack<int> st;
    st.push(u);
    while (!st.empty())
    {
        int s = st.top();
        st.pop();
        if (!visited[s])
            visited[s] = true;
        for (int c: list[s])
        {
            if ((s == x && c == y) || (s == y && c == x))
                continue;
            else
            {
                if (!visited[c])
                {
                    st.push(c);
                    visited[c] = true;
                }
            }
        }
    }
    
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int v, e; cin >> v >> e;
        vector<vector<int>> list(v+1);
        vector<pair<int, int>> edge(e+1);
        for (int i = 1; i <= e; i++)
        {
            int n, k;
            cin >> n >> k;
            edge[i] = {n,k};
            list[n].push_back(k);
            list[k].push_back(n);
        }
        for (int i = 1; i <= e; i++)
        {
            int lienthong = 0;
            int x = edge[i].first;
            int y = edge[i].second;
            vector<bool> visited(v+1, false);
            for (int j = 1; j <= v; j++)
            {
                if (!visited[j])
                {
                    DFS(j, list, visited, x, y);
                    lienthong++;
                }
            }
            if (lienthong > 1)
                cout << x << " " << y << " ";
        }
        cout << endl;
    }
    
    return 0;
}