#include<bits/stdc++.h>
using namespace std;

void solve(string s)
{
    int count = 0;
    stack<pair<char,int>> st;
    st.push({')',-1});
    for (int i = 0; i < s.length(); i++)
    {
        if (st.top().first == '(' && s[i] == ')')
            st.pop();
        else
            st.push({s[i], i});
    }

    int n = s.length();
    int ans = 0;

    while (!st.empty())
    {
        ans = max(ans, n - st.top().second - 1 );
        n = st.top().second;
        st.pop();
    }
    cout << ans << endl;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        solve(s);
    }
    return 0;
}