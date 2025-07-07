#include<bits/stdc++.h>
using namespace std;

void solve(int n, int a[])
{
    int b[n];
    memset(b, -1, sizeof(b));
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
            st.push(i);
        else
        {
            while (!st.empty() && a[i] > a[st.top()])
            {
                b[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
            
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        solve(n, a);
    }
    return 0;
}