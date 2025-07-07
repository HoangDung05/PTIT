#include<iostream>
#include<map>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        map<int, int> mp;
        int k, num_appearMax = -1, appearMax = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            mp[k]++;
        }
        for (auto c: mp)
        {
            if (c.second > appearMax && c.second > n/2)
            {
                num_appearMax = c.first;
            }
        }
        if (num_appearMax == -1)
            cout << "NO" << endl;
        else
            cout << num_appearMax << endl;
    }
    
}