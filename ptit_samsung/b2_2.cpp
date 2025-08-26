#include<bits/stdc++.h>
#define ll long long
using namespace std;

void phantichSNT(ll x, map<ll, int> &prime)
{
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
            {
                prime[i]++;
                x /= i;
            }
        }
    }

    if (x > 1)
        prime[x]++;
}


int main()
{
    int n, m; cin >> n >> m;
    vector<int> result;
    map<ll, int> a_prime;
    vector<ll> a(n);
    vector<vector<ll>> b(m+1, vector<ll>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        phantichSNT(a[i], a_prime);
    }
        
    for (int i = 1; i <= m; i++)
    {
        map<ll, int> b_prime;
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
            phantichSNT(b[i][j], b_prime);
        }
        
        bool ok = true;
        for (auto &[p, c]: b_prime)
        {
            if (a_prime[p] < c)
            {
                ok = false;
                break;
            }
        }

        if (ok) 
            result.push_back(i);
    }
    
    cout << result.size() << endl;
    for (auto &c: result)
        cout << c << " ";
    return 0;
}