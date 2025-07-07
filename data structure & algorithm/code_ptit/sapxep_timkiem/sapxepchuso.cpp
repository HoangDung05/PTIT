#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void addNum(set<int> &num, ll k)
{
    while (k > 0)
    {
        num.insert(k % 10);
        k /= 10;
    }
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        set<int> num;
        ll k;
        while (n--)
        {
            cin >> k;
            addNum(num, k);
        }
        for (auto c: num)
            cout << c << " ";
        cout << endl;
    }
    
    return 0;
}