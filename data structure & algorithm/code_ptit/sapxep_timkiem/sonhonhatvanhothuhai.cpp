#include<iostream>
#include<set>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, k; cin >> n;
        set<int> se;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            se.insert(k);
        }
        if (se.size() == 1)
            cout << -1 << endl;
        else
        {
            auto it = se.begin();
            cout << *it << " ";
            it++;
            cout << *it << endl;
        }
    }
    
    return 0;
}