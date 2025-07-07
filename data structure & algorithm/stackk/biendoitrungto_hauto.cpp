#include<bits/stdc++.h>
using namespace std;

int priority(char p)
{
    if (p == '+' || p == '-')
        return 1;
    if (p == '*' || p == '/')
        return 2;
    if (p == '^')  
        return 3;
    return 0;
}

string Trungto_Hauto(string s)
{
    stack<char> st;
    string out = "";
    for (char x: s)
    {
        if (x == '(')
        {
            st.push(x);
        }
        else if (x == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                out += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else if (isalnum(x))
        {
            out += x;
        }
        else
        {
            while (!st.empty() && st.top() != '(' && priority(st.top()) >= priority(x))
            {
                out += st.top();
                st.pop();
            }
            st.push(x);
        }
    }
    while (!st.empty())
    {
        out += st.top();
        st.pop();
    }
    return out;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << Trungto_Hauto(s) << endl;
    }
    return 0;
}