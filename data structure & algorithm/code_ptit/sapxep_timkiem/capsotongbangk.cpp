#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        unordered_map<int, int> mp;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = 0;
        for (auto c: a)
        {
            ans += mp[k - c];
            mp[c]++;
        }
        cout << ans << endl;
    }
    
}