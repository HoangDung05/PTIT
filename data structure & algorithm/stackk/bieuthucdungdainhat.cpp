#include<bits/stdc++.h>
using namespace std;

void solve(string s)
{
    stack<int> st;
    int count = 0;
    for (char c: s)
    {
        if (c == '(')
            st.push(c);
        else
        {
            if (!st.empty())
            {
                count += 2;
                st.pop();
            }
        }
            
    }
    cout << count << endl;
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