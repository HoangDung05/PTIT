#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int t, n, k;
    cin >> t >> n;
    vector<vector<int>> v(n, vector<int>(n,0));
    vector<int> bac(n, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> v1;
        for (int j = 0; j < n; j++)
        {
            cin >> k;
            bac[i] += k;
            v1.emplace_back(k);
        }
        v.emplace_back(v1);
    }
    if (t == 1)
    {
        for (auto c: bac)
            cout << c << " ";
    }
    else
    {
        cout << n;
        for (int i = 1; i <= n; i++)
        {
            cout << bac[i];
            for (int j = 1; j <= n; j++)
            {
                if (v[i][j])
                {
                    cout << " " << j;
                }
            }
        }
        
    }
    
    return 0;
}