#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        ll a[n];
        for (ll &c: a)
            cin >> c;
        stack<int> st;
        long long res = -1;
        int i = 0;
        while (i < n)
        {
            if (st.empty() || a[i] >= a[st.top()])
            {
                st.push(i);
                ++i;
            }
            else
            {
                int idx = st.top();
                st.pop();
                if(st.empty())
                {
                    res = max(res, a[idx] * i);
                }
                else
                {
                    res = max(res, a[idx] * (i - st.top() - 1));
                }
            }
        }
        while (!st.empty())
        {
            int idx = st.top();
            st.pop();
            if(st.empty())
            {
                res = max(res, a[idx] * i);
            }
            else
            {
                res = max(res, a[idx] * (i - st.top() - 1));
            }
        }
        cout << res << endl;
    }
    
}