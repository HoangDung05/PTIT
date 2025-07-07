#include<iostream>
#include<set>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m;
        long long k;
        cin >> n >> m;
        set<long long> se1, se2;
        while (n--)
        {
            cin >> k;
            se1.insert(k);
        }
        while (m--)
        {
            cin >> k;
            se2.insert(k);
        }
        auto it1 = se1.rbegin();
        auto it2 = se2.begin();
        long long multiple = *it1 * *it2;
        cout << multiple << endl;
    }
    
    return 0;
}