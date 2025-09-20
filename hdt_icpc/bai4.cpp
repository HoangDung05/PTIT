#include<bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    set<int> st;
    while (q--)
    {
        string s; cin >> s;
        if (s == "add") {
            int x; cin >> x;
            st.insert(x);
        }
        else if (s == "del") {
            int x; cin >> x;
            auto f = s.find(x);
            if (f != s.end())
            
        }
    }
    
    return 0;
}