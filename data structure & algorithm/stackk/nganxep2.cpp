#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    string s;
    int q; cin >> q;

    while (q--)
    {
        cin >> s;
        if (s == "PUSH")
        {
            int x; cin >> x;
            st.push(x);
        }
        else if (s == "POP"){
            if (!st.empty()){
                st.pop();
            }
        }
        else if (s == "PRINT"){
            if (st.empty()){
                cout << "NONE\n";
            }
            else {
                cout << st.top() << endl;
                // int k;
                // stack<int> tempStack = st;

                // while (!tempStack.empty())
                // {
                //     k = tempStack.top();
                //     tempStack.pop();
                // }
                // cout << k << endl; 
            }  
        }
    }
    return 0;
}