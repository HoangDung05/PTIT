#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string n; cin >> n;
        int cnt = 0;
        queue<string> q;
        q.push("1");
        while (!q.empty())
        {
            string x = q.front();
            q.pop();
            
            if (x.length() > n.length() || (x.length() == n.length() && x > n))
                break;
            cnt++;
            q.push(x + "0");
            q.push(x + "1");
        }
        cout << cnt << endl;
    }
    
    return 0;
}