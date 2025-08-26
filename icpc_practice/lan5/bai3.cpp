#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, r, c;
    cin >> M >> N >> r >> c;

    vector<vector<int>> A(M+1, vector<int>(N+1));
    int minVal = INF, maxVal = -INF;

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            minVal = min(minVal, A[i][j]);
            maxVal = max(maxVal, A[i][j]);
        }
    }

    auto ok = [&](int mid) {
        // Bảng nhị phân: 1 nếu <= mid
        vector<vector<int>> P(M+1, vector<int>(N+1, 0));
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                int val = (A[i][j] <= mid);
                P[i][j] = val + P[i-1][j] + P[i][j-1] - P[i-1][j-1];
            }
        }

        int need = (r*c)/2 + 1;
        for (int i = r; i <= M; i++) {
            for (int j = c; j <= N; j++) {
                int total = P[i][j] - P[i-r][j] - P[i][j-c] + P[i-r][j-c];
                if (total < need) return false; // có 1 bảng con không thỏa
            }
        }
        return true;
    };

    int lo = minVal, hi = maxVal, ans = maxVal;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
