#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> edge;
vector<vector<int>> lienthuoc;
vector<vector<int>> a;
vector<int> ke[105];
vector<int> deg_ra(1000), deg_vao(1000);

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    

    int t, n; cin >> t >> n;
    a.resize(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int x; cin >> x;
            deg_ra[i]++;
            deg_vao[x]++;
            a[i][x] = 1;
        }
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
            cout << deg_vao[i] << " " << deg_ra[i] << endl;
    }

    else if (t == 2)
    {
        cout << n << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }

    }
    return 0;
}