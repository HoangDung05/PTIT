#include<bits/stdc++.h>
using namespace std;

//chuyen so thap phan sang nhi phan
// void reverse(int n){
//     stack<int> st;
//     while (n != 0)
//     {
//         st.push(n % 2);
//         n /= 2;
//     }
//     if (n == 1)
//         st.push(1);
//     while (!st.empty())
//     {
//         cout << st.top();
//         st.pop();
//     }
//     cout << endl;
// }

//in nguoc xau
// void display_adverseString(string s)
// {
//     stack<string> st;
//     stringstream ss(s);
//     string word;
//     while (ss >> word)
//     {
//         st.push(word);
//     }
//     while (!st.empty())
//     {
//         cout << st.top() << " ";
//         st.pop();
//     }
// }



int main()
{
    // int n; cin >> n;
    // reverse(n);

    // string s;
    // getline(cin, s);
    // display_adverseString(s);

    int n; cin >> n;
    int a[n], b[n];
    stack<int> st;
    for (auto &c: a)
        cin >> c;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            while (!st.empty() && a[st.top()] < a[i])
            {
                b[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty())
    {
        b[st.top()] = -1;
        st.pop();
    }
    for (int x: b)
        cout << x << " ";

    return 0;
}