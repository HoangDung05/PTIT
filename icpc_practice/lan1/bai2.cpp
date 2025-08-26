#include<bits/stdc++.h>
#include "bai2.h"
using namespace std;
const int MOD = 1e9 + 7;


int main()
{
    string s; cin >> s;
    int n = s.length();
    int k; cin >> k;
    vector<string> dict(k);
    for (int i = 0; i < k; i++)
    {
        cin >> dict[i];
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (const string& w:dict)
        {
            int len = w.length(); 
            if (i >= len && (s.substr(i - len, len)) == w)
                dp[i] += dp[i - len] % MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}