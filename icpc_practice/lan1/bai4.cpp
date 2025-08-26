#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x: a)
        cin >> x;
    
    multiset<int> ends;
    for (int i = 0; i < n; i++)
    {
        auto it = ends.lower_bound(a[i]);
        if (it == ends.begin())
        {
            ends.insert(a[i]); //không tìm thấy giá trị lớn nhất < a[i]
        }
        else
        {
            --it;
            ends.erase(it);
            ends.insert(a[i]);
        }
    }
    cout << ends.size();
    return 0;
}