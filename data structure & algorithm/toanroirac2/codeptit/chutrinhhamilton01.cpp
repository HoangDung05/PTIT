// Cho trước đồ thị G = (V, E) gồm n đỉnh biểu diễn dưới dạng ma trận kề và một đỉnh u.
// Tìm tất cả các chu trình Hamilton của G bắt đầu tại u.

#include <bits/stdc++.h>
using namespace std;

int n, u;
vector<vector<int>> a;
vector<int> path;
bool visited[105];
vector<vector<int>> all_cycles;

void findHamiltonCycles(int pos) {
    if (pos == n) {
        if (a[path.back()][path[0]]) {
            all_cycles.push_back(path);
        }
        return;
    }

    for (int v = 1; v <= n; v++) {
        if (a[path[pos-1]][v] && !visited[v]) {
            visited[v] = true;
            path[pos] = v;
            findHamiltonCycles(pos + 1);
            visited[v] = false;
        }
    }
}

int main() {
    // Nhập input từ bàn phím thay vì file
    cin >> n >> u;
    a.resize(n+1, vector<int>(n+1));
    path.resize(n);
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    path[0] = u;
    memset(visited, false, sizeof(visited));
    visited[u] = true;

    findHamiltonCycles(1);
    
    // Xuất kết quả ra màn hình
    cout << all_cycles.size() << endl;
    if (!all_cycles.empty()) {
        for (auto& cycle : all_cycles) {
            for (int x : cycle) cout << x << " ";
            cout << cycle[0] << endl;
        }
    }
    
    return 0;
}