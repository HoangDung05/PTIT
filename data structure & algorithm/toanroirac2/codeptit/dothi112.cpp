#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> edge;
vector<int> deg_ra(1000), deg_vao(1000);

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n; cin >> t >> n;
    int x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            if (x)
            {
                deg_ra[i]++;
                deg_vao[j]++;
                edge.push_back({i, j});
            }
        }
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
            cout << deg_vao[i] << " " << deg_ra[i] << endl;
    }

    else if (t == 2)
    {
        cout << n << " " << edge.size() << endl;
        for (auto [x, y]: edge)
            cout << x << " " << y << endl;
    }
    return 0;
}