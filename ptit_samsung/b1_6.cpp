#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<int> state;
    int dist;
};

vector<int> rotateLeft(const vector<int>& s) {
    vector<int> t = s;
    // vị trí 4 ô bên trái: 0,1,3,4
    t[0] = s[3];
    t[1] = s[0];
    t[4] = s[1];
    t[3] = s[4];
    return t;
}

vector<int> rotateRight(const vector<int>& s) {
    vector<int> t = s;
    // vị trí 4 ô bên phải: 1,2,4,5
    t[1] = s[4];
    t[2] = s[1];
    t[5] = s[2];
    t[4] = s[5];
    return t;
}

int bfs(vector<int> start, vector<int> goal) {
    queue<Node> q;
    unordered_set<string> visited;

    auto vecToStr = [](const vector<int>& v) {
        string s;
        for (int x : v) s += char('0' + x);
        return s;
    };

    q.push({start, 0});
    visited.insert(vecToStr(start));

    while (!q.empty()) {
        Node cur = q.front(); q.pop();

        if (cur.state == goal) return cur.dist;

        vector<int> next1 = rotateLeft(cur.state);
        vector<int> next2 = rotateRight(cur.state);

        string s1 = vecToStr(next1);
        if (!visited.count(s1)) {
            visited.insert(s1);
            q.push({next1, cur.dist + 1});
        }

        string s2 = vecToStr(next2);
        if (!visited.count(s2)) {
            visited.insert(s2);
            q.push({next2, cur.dist + 1});
        }
    }

    return -1; // không thể
}

int main() {
    vector<int> start(6), goal(6);
    for (int i = 0; i < 6; i++) cin >> start[i];
    for (int i = 0; i < 6; i++) cin >> goal[i];

    cout << bfs(start, goal);
    return 0;
}
