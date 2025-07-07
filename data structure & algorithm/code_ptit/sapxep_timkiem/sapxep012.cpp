#include<iostream>
#include<set>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        multiset<int> se;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            se.insert(k);
        }
        for (auto c: se)
            cout << c << " ";
        cout << endl;
    }
    return 0;
}