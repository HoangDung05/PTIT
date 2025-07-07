#include<bits/stdc++.h>
using namespace std;

int solve(int x, int y, char c)
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

void kq(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            if (st.size() >= 2)
            {
                int y = st.top(); st.pop();
                int x = st.top(); st.pop();
                int result = solve(x, y, s[i]);
                st.push(result);
            }
        }
    }
    cout << st.top() << endl;
}

int main()
{
    int t; cin >> t;
    cin.ignore();
    while (t--)
    {
        string s; cin >> s;
        kq(s);
    }
    return 0;
}