#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ucln(ll a, ll b)
{
    while (b > 0)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll solve_b(ll a, string b)
{
    ll mod = 0;
    for (int i = 0; i < b.length(); i++)
    {
        mod = (mod * 10 + b[i]) % a;
    }
    return mod;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll a; cin >> a;
        string b; cin >> b;
        cout << ucln(a, solve_b(a, b)) << endl;
    }
    return 0;
}