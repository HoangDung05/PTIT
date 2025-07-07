#include<iostream>
#include<algorithm>
using namespace std;

void solve(int a[], int n, int x)
{
    int first = lower_bound(a, a + n, x) - a;
    int last = upper_bound(a, a + n, x) - a;
    int dem = last - first;
    if (dem == 0)
    {
        cout << -1 << endl;
    }
    else
        cout << dem << endl;
    
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, x; cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(a, n, x);
    }
    
    return 0;
}