#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
int n, m;
vector<int> adj[MAX];
vector<bool> visited(MAX, false);
stack<int> s; // khai báo ngăn xếp s
vector<int> ans;

void DFS(int u)
{
    s.push(u); // đưa đỉnh u vào ngăn xếp
    visited[u] = true; // xác nhận đỉnh u đã duyệt
    while (!s.empty())
    {
        int t = s.top(); // lấy đỉnh ở đầu ngăn xếp
        s.pop();
        if (find(ans.begin(), ans.end(), t) == ans.end())
            ans.push_back(t);
        for (int c: adj[t])
        {
            if (!visited[c])
            {
                visited[c] = true;
                s.push(t);
                s.push(c);
                break;
            }
        }
    }
}


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int ui, vi;
        cin >> ui >> vi;
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }
    DFS(1);
    for (auto c: ans)
        cout << c << " ";
}