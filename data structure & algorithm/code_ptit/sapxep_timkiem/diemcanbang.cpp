#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int balanceIndex(vector<int> a, int n)
{
    if (n == 0)
        return -1;
    ll totalSum = 0;
    for (auto c: a)
        totalSum += c;
    ll leftSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum -= a[i]; //totalSum nhu la tong ben phai
        if (leftSum == totalSum)
            return i + 1;
        leftSum += a[i];
    }
    return -1;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << balanceIndex(a, n) << endl;
    }
    return 0;
}