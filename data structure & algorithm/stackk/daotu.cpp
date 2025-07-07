#include<bits/stdc++.h>
using namespace std;

//in nguoc xau
void display_adverseString(string s)
{
    stack<string> st;
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        st.push(word);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    int t; cin >> t;
    cin.ignore();
    while (t--)
    {
        string s; getline(cin, s);
        display_adverseString(s);
    }
    
}