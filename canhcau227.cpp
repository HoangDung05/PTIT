// Cho trước đồ thị vô hướng G = (V, E) gồm n đỉnh biểu diễn dưới dạng ma trận kề.
// Tìm các cạnh cầu của G sử dụng thuật toán tìm kiếm theo chiều sâu (DFS).

#include <bits/stdc++.h>
using namespace std;

int n, timer;
vector<vector<int>> adj;
vector<int> disc, low;
vector<pair<int, int>> bridges;

void dfs(int u, int parent = -1) {
    disc[u] = low[u] = ++timer;
    for (int v = 0; v < n; ++v) {
        if (adj[u][v]) {
            if (v == parent) continue; // Bỏ qua cạnh về cha
            if (disc[v] == 0) { // Đỉnh chưa thăm
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    // Tìm thấy cạnh cầu
                    bridges.push_back({min(u, v), max(u, v)});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
}

void findBridges() {
    timer = 0;
    disc.assign(n, 0);
    low.assign(n, 0);
    bridges.clear();
    
    for (int i = 0; i < n; ++i) {
        if (disc[i] == 0) {
            dfs(i);
        }
    }
    
    // Sắp xếp theo thứ tự từ điển
    sort(bridges.begin(), bridges.end());
}

int main() {
    ifstream inFile("TK.INP");
    ofstream outFile("TK.OUT");
    
    inFile >> n;
    adj.resize(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inFile >> adj[i][j];
        }
    }
    
    findBridges();
    
    outFile << bridges.size() << endl;
    for (auto& bridge : bridges) {
        outFile << bridge.first + 1 << " " << bridge.second + 1 << endl;
    }
    
    inFile.close();
    outFile.close();
    return 0;
}