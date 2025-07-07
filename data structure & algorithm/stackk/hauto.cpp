#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll x, ll y, char c)
{
    switch (c)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    }
    return 0;
}

int isNum(string s)
{
    for (auto c: s)
    {
        if (c >= '0' && c <= '9')
            return 1;
    }
    return 0;
}

void kqua(int n, string a[])
{
    stack<ll> st;
    for (int i = 0; i < n; i++)
    {
        if (isNum(a[i]))
        {
            ll k = stoll(a[i]);
            st.push(k);
        }
        else
        {
            ll y = st.top(); st.pop();
            ll x = st.top(); st.pop();
            ll result = solve(x, y, a[i][0]);
            st.push(result);
        }
    }
    cout << st.top() << endl;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i]; 
        kqua(n, a);
    }
    return 0;
}