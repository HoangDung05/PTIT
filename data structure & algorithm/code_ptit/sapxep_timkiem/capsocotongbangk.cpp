#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        ll k; cin >> k;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        unordered_map<ll, ll> mp;
        ll ans = 0;
        for (auto c: v)
        {
            ans += mp[k - c];
            mp[c]++;
        }
        cout << ans << endl;
    }
    
}