#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a, b;
        int x, l = 0, r = n - 1;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }
        b = a;
        sort(a.begin(), a.end());
        while (a[l] == b[l])
        {
            l++;
        }
        while (a[r] == b[r])
        {
            r--;
        }
        cout << l + 1 << " " << r + 1 << endl;
    }
    return 0;    
}