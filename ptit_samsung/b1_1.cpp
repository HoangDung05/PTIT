#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[100005] = {0}, bit[100005] = {0};
int n, q;

void update(int p, int x)
{
    while (p <= n)
    {
        bit[p] += x;
        p += (p & (-p));
    }
}

ll getSum(int u)
{
    ll sum = 0;
    while (u >= 1)
    {
        sum += bit[u];
        u -= (u & (-u));
    }
    return sum;
}

int main()
{
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
        
    
    for (int i = 1; i <= q; i++)
    {
        int t; cin >> t;
        if (t == 1)
        {
            int p, x; cin >> p >> x;
            update(p, x);
        }
        else if (t == 2)
        {
            int u, v; cin >> u >> v;
            cout << getSum(v) - getSum(u - 1) << endl;
        }
    }
    return 0;
}

