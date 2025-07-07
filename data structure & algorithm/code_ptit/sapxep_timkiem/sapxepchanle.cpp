#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n;
    int a[n] = {0};
    vector<int> odd, even;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        (i % 2 == 0) ? even.push_back(k) : odd.push_back(k);  
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end(), greater<int>());
    for (int i = 0; i < n/2; i++)
    {
        cout << odd[i] << " " << even[i] << " ";
    }
    if (n % 2 != 0) cout << odd[n/2 + 1];
    return 0;
}