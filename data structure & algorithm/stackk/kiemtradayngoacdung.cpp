#include<bits/stdc++.h>
using namespace std;

int check(string s){
    stack<char> st;
    for (char c: s)
    {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else
        {
            if (st.empty())
                return 0;
            if (c == ')' && st.top() != '(')
                return 0;
            else if (c == '}' && st.top() != '{')
                return 0;
            else if (c == ']' && st.top() != '[')
                return 0;
            st.pop();
        }
    }
    if (st.empty())
        return 1;
    return 0;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        if (check(s))
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}