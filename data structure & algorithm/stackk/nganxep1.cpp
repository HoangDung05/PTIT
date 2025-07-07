#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    string s;

    while (cin >> s)
    {
        if (s == "push")
        {
            int x; cin >> x;
            st.push(x);
        }
        else if (s == "pop"){
            if (!st.empty()){
                st.pop();
            }
        }
        else if (s == "show"){
            if (st.empty()){
                cout << "empty\n";
            }
            else {
                vector<int> temp;
                stack<int> tempStack = stable_sort;

                while (!tempStack.empty())
                {
                    temp.push_back(tempStack.top());
                    tempStack.pop();
                }
                
                for (int i = temp.size() - 1; i >= 0; i--){
                    cout << temp[i];
                    if (i > 0) 
                        cout << " ";
                }
                cout << endl;
            }
            
        }
    }
    
    return 0;
}