#include<bits/stdc++.h>
using namespace std;

vector<int> deg_ra(105), deg_vao(105);
vector<vector<int>> a;


int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m; cin >> t >> n >> m;
    a.resize(n+1, vector<int>(n+1, 10000));
    for (int i = 1; i <= m; i++)
    {
        int dau, cuoi, trongso;
        cin >> dau >> cuoi >> trongso;
        deg_ra[dau]++;
        deg_vao[cuoi]++;
        a[dau][cuoi] = trongso;
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << deg_vao[i] << " " << deg_ra[i] << endl;
        }
    }

    else if (t == 2)
    {
        cout << n << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    cout << 0 << " ";
                else
                    cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}