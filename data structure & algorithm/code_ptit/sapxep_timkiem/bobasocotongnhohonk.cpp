#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;
        ll ans = 0;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                if (a[i] + a[left] + a[right] < k)
                {
                    ans += right - left;
                    left++;
                }
                else
                    right--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}