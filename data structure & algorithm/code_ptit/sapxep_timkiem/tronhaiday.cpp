#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int k;
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            cin >> k;
            v.push_back(k);
        }
        for(int i = 0; i < m; i++)
        {
            cin >> k;
            v.push_back(k);
        }
        sort(v.begin(), v.end());
        for (auto c: v)
            cout << c << " ";
        cout << endl;
    }
    
    return 0;
}