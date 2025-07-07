#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        queue<int> q;
        int k;
        while (n--)
        {
            cin >> k;
            if (k == 1)
            {
                cout << q.size() << endl;
            }
            else if (k == 2)
            {
                if (q.empty())
                    cout << "YES\n";
                else 
                    cout << "NO\n";
            }
            else if (k == 3)
            {
                int p; cin >> p;
                q.push(p);
            }
            else if (k == 4)
            {
                if (!q.empty())
                    q.pop();
            }
            else if (k == 5)
            {
                if (q.empty())
                    cout << -1 << endl;
                else 
                    cout << q.front() << endl;
            }
            else if (k == 6)
            {
                if (q.empty())
                    cout << -1 << endl;
                else 
                    cout << q.back() << endl;
            }
        }
        
    }
    
    return 0;
}