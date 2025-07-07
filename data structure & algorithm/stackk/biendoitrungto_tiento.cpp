#include<bits/stdc++.h>
using namespace std;

int priority(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

void solve(string s)
{
    string tmp = "";
    for (int i = s.length()-1; i >= 0; i--)
    {
        if (s[i] == '(')
            tmp += ')';
        else if (s[i] == ')')
            tmp += '(';
        else   
            tmp += s[i];
    }

    //chuyen tmp thanh hau to
    stack<char> st;
    string result = "";
    for (char c: tmp)
    {
        if (isalnum(c))
            result += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else    
        {
            if (!st.empty() && st.top() != '(' && priority(st.top()) >= priority(c))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    for (int i = result.length() - 1; i >= 0; i--)
        cout << result[i];
    cout << endl;
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