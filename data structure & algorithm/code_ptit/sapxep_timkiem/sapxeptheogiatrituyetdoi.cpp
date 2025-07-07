#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        cin >> x;
        int k;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            int f = abs(x - k);
            v.emplace_back(k, f);
        }
        stable_sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b)
            {
                return a.second < b.second;
            });
        for (auto c: v)
        {
            cout << c.first << " ";
        }
        cout << endl;
    }
    
    return 0;
}