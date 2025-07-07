#include<bits/stdc++.h>
using namespace std;

void solve(string s)
{
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        string tmp = string(1, s[i]);
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            string x = st.top(); st.pop();
            string y = st.top(); st.pop();
            string result = "(" + x + tmp + y + ")";
            st.push(result);
        }
        else
        {
            st.push(tmp);
        }
    }
    cout << st.top() << endl;
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