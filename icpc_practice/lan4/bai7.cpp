#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll a, b, c, d; 
        cin >> a >> b >> c >> d;
        ll g = gcd(c-b, d);

        ll period = d / g;

        
        ll cnt = 0;
        for (ll k = 1; k <= period; k++)
        {

            ll x = a + b*k;
            ll y = a + c*k;
            if (x/d == (y - 1)/d)
                cnt++;
        }
        cout << cnt - 2 << endl;
    }
    
    return 0;
}