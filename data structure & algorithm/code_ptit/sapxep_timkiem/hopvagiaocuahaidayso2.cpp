#include<iostream>
#include<set>
using namespace std;

void solve()
{
    int n, m, x;
    cin >> n >> m;
    set<int> merge, intersect;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        merge.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        if (merge.find(x) != merge.end())
        {
            intersect.insert(x);
        }
        else
            merge.insert(x);
    }
    for (auto c: merge)
        cout << c << " ";
    cout << endl;
    for (auto c: intersect)
        cout << c << " ";
    cout << endl;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}