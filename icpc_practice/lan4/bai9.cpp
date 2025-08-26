#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sumDigit(ll n) 
{
    int sum = 0;
    while (n > 0) 
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

ll convert(string s)
{
    ll ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ans = ans * 10 + (s[i] - '0');
    }
    return ans;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string n; cin >> n;
        int s; cin >> s;
        if (sumDigit(convert(n)) <= s)
        {
            cout << "0\n";
            continue;
        }
        int len = n.size();
        ll ans = 0;
        string k = n;
        for (int i = len - 1; i >= 0; i--) {
            if (k[i] == '9')
                continue;
            k[i] = (char)(k[i] + 1);
            for (int j = i + 1; j < len; j++)
                k[j] = '0';
            if (sumDigit(convert(k)) <= s)
            {
                ans = convert(k) - convert(n);
                break;
            }
        }
        if (ans == 0)
        {
            string temp = "";
            temp += '1';
            for (int i = 0; i < len; i++)
                temp += '0';
            ans = convert(temp) - convert(n);
        }
        cout << ans << endl;
    }
    return 0;
}