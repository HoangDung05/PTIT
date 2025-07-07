#include<iostream>
#include<unordered_map>
#include<stdbool.h>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        unordered_map<int, int> mp;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        vector<pair<int, int>> v(mp.begin(), mp.end()); //đưa các phần tử của mp vào vecto v
        sort(v.begin(), v.end(), cmp);
        for (auto c: v)
        {
            for (int i = 0; i < c.second; i++)
                cout << c.first << " ";
        }
        cout << endl;
    }
    return 0;
}