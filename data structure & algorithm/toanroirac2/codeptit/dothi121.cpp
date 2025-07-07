#include<bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> edge;
vector<vector<int>> lienthuoc;
vector<vector<int>> a;
vector<int> ke[105];
vector<int> deg_ra(1000), deg_vao(1000);

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    
    int t, n; cin >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x; cin >> x;
            if (x > 0 && x <= 50)
            {
                deg_ra[i]++;
                deg_vao[j]++;
                edge.push_back({i, j, x});
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
        int m = edge.size();
        for (auto [x, y, z]: edge)
        {
            cout << x << " " << y << " " << z << endl;
        }
    }
    return 0;
}