#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
    int index;
    int x, y;
    double g, f;
    int color; // 0: unvisited, 1: Open, 2: Closed
    int parent;
};

double heuristic(const Node& a, const Node& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void aStar(int graph[100][100], Node nodes[], int n, int start, int finish) {
    vector<Node> open;
    nodes[start].g = 0;
    nodes[start].f = heuristic(nodes[start], nodes[finish]);
    nodes[start].color = 1;
    open.push_back(nodes[start]);

    while (!open.empty()) {
        // Tìm đỉnh có f nhỏ nhất trong Open
        int current_idx = 0;
        for (int i = 1; i < open.size(); i++) {
            if (open[i].f < open[current_idx].f) {
                current_idx = i;
            }
        }
        Node current = open[current_idx];

        // Kiểm tra nếu là đích
        if (current.index == finish) {
            // Truy vết đường đi
            vector<int> path;
            int node = finish;
            while (node != start) {
                path.push_back(node);
                node = nodes[node].parent;
            }
            path.push_back(start);
            reverse(path.begin(), path.end());

            // In kết quả
            cout << "Duong di: ";
            for (int i = 0; i < path.size(); i++) {
                cout << path[i] << " (" << nodes[path[i]].x << "," << nodes[path[i]].y << ")";
                if (i != path.size() - 1) cout << " -> ";
            }
            cout << "\nTong khoang cach: " << current.g << endl;
            return;
        }

        // Chuyển đỉnh hiện tại từ Open sang Closed
        open.erase(open.begin() + current_idx);
        nodes[current.index].color = 2;

        // Duyệt các đỉnh kề
        for (int i = 0; i < n; i++) {
            if (graph[current.index][i] > 0) { // Có cạnh nối
                double new_g = current.g + graph[current.index][i];

                // Nếu đỉnh chưa được xét hoặc có đường đi tốt hơn
                if (nodes[i].color == 0 || new_g < nodes[i].g) {
                    nodes[i].g = new_g;
                    nodes[i].f = new_g + heuristic(nodes[i], nodes[finish]);
                    nodes[i].parent = current.index;

                    if (nodes[i].color != 1) {
                        nodes[i].color = 1;
                        open.push_back(nodes[i]);
                    }
                }
            }
        }
    }
    cout << "Khong tim thay duong di!\n";
}

int main() {
    int n = 4;
    int start = 0, finish = 3;
    Node nodes[100] = {
        {0, 0, 0}, // Đỉnh 0
        {1, 1, 2}, // Đỉnh 1
        {2, 3, 1}, // Đỉnh 2
        {3, 4, 3}  // Đỉnh 3
    };
    int graph[100][100] = {
        {0, 3, 5, 0},
        {3, 0, 2, 4},
        {5, 2, 0, 1},
        {0, 4, 1, 0}
    };

    // Chạy A*
    aStar(graph, nodes, n, start, finish);

    return 0;
}