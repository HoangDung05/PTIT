#include<iostream>
#include<set>
using namespace std;
int main()
{
    int t; cin >> t;
    int k;
    set<int> se;
    while (t--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; i++)
        { 
            cin >> k;
            se.insert(k);
        }
        int l = *se.begin(), r = *se.rbegin();
        int dem = r - l + 1 - se.size();
        cout << dem << endl;
        se.clear();
    }
    
    return 0;
}