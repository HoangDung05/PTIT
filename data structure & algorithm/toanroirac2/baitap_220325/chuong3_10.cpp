#include <bits/stdc++.h>
using namespace std;

void dfs1(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs1(v, adj, visited, st);
    }
    st.push(u);
}

void dfs2(int u, vector<vector<int>> &transpose, vector<bool> &visited, vector<int> &component) {
    visited[u] = true;
    component.push_back(u);
    for (int v : transpose[u]) {
        if (!visited[v]) dfs2(v, transpose, visited, component);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1), transpose(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        transpose[v].push_back(u);
    }
    
    vector<bool> visited(n + 1, false);
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs1(i, adj, visited, st);
    }
    
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (!visited[u]) {
            vector<int> component;
            dfs2(u, transpose, visited, component);
            sort(component.begin(), component.end());
            sccs.push_back(component);
        }
    }
    
    cout << sccs.size() << "\n";
    for (const auto &comp : sccs) {
        for (int v : comp) cout << v << " ";
        cout << "\n";
    }
    
    return 0;
}

