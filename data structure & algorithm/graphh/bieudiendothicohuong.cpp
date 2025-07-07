#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int v, e; cin >> v >> e;
        vector<vector<int>> vt(v+1);
        for (int i = 0; i < e; i++)
        {
            int dau, cuoi; 
            cin >> dau >> cuoi;
            vt[dau].push_back(cuoi);
        }
        for (int i = 1; i <= v; i++)
        {
            cout << i << ": ";
            for (int c: vt[i])
                cout << c << " ";
            cout << endl; 
        }
    }
    return 0;
}