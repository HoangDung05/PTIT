#include<bits/stdc++.h>
#define ll long long
using namespace std;

int prime[10000001];
vector<int> snt;

void sangSNT()
{
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= sqrt(10000000); i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j <= 10000000; j += i)
            {
                prime[j] = 0;
            }
        }
    }

    for (int i = 2; i <= 10000000; i++)
    {
        if (prime[i])
        {
            snt.push_back(i);
        }   
    }
}

void solve(ll n)
{
    map<ll, int> save;
    for (ll x: snt)
    {
        if (x * x > n) 
            break;
        if (n % x == 0)
        {
            while (n % x == 0)
            {
                save[x]++;
                n /= x;
            }
        }
    }
    if (n > 1)
        save[n]++;
    for (auto x: save)
        cout << x.first << " " << x.second << endl;
}

int main()
{
    int t; cin >> t;
    sangSNT();
    while (t--)
    {
        ll n; cin >> n;
        solve(n);
    }
    return 0;
}