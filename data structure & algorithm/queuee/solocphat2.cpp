#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        queue<string> q;
        q.push("6");
        q.push("8");
        vector<string> luckyNumber;
        while (1)
        {
            string top = q.front();
            q.pop();
            if (top.size() > n)
                break;
            luckyNumber.push_back(top);
            q.push(top + "6");
            q.push(top + "8");
        }
        cout << luckyNumber.size() << endl;
        for (auto c: luckyNumber)
            cout << c << " ";
        cout << endl;
    }
    
    return 0;
}