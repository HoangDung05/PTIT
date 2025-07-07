#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        bool check = false;
        for (int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
                if(binary_search(a.begin() + j + 1, a.end(), k - a[i] - a[j]))
                {
                    check = true;
                    cout << "YES\n";
                    break;
                }
            if (check)
                break;
        }
        if (!check)
            cout << "NO\n";
    }
    
    return 0;
}