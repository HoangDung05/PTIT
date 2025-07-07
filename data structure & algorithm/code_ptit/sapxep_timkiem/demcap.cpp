#include<bits/stdc++.h>
using namespace std;

int countPairs(int x, vector<int> &y, vector<int> &countY)
{
    if (x == 0) return 0;
    if (x == 1) return countY[0];
    int idx = upper_bound(y.begin(), y.end(), x) - y.begin();
    int ans = y.size() - idx;
    ans += countY[1] + countY[0];
    if (x == 2) ans -= (countY[3] + countY[4]);
    if (x == 3) ans += countY[2];
    return ans;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> x(n), y(m), countY(5, 0);
        for(int i = 0; i < n; i++)
            cin >> x[i];
        for(int i = 0; i < m; i++)
        {
            cin >> y[i];
            if (y[i] < 5)
                countY[y[i]]++;
        }
        sort(y.begin(), y.end());
        int total_pairs = 0;
        for (int i = 0; i < n; i++)
            total_pairs += countPairs(x[i], y, countY);
        cout << total_pairs << endl;
    }
    return 0;
}