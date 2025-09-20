#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

l -> r
pre[r] - pre[l - 1] = (r - l + 1)
pre[r] - r = pre[l] - (l - 1)
mp[pre[r] - r; r]



int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n+1), pre(n+1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = (pre[i-1] + a[i]) % k;
    }
    
    map<ll, vector<ll>> mp;
    ll ans = 0;
    
    for (ll i = 0; i <= n; i++) {
        ll val = (pre[i] - i % k + k) % k;
        
        if (mp.find(val) != mp.end()) {
            vector<ll> &v = mp[val];
            ll bound = i - k + 1;
            ll pos = lower_bound(v.begin(), v.end(), bound) - v.begin();
            ans += (v.size() - pos);
        }
        
        mp[val].push_back(i);
    }
    
    cout << ans;
    return 0;
}

0 1 2 3 4 5