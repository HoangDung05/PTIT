#include<bits/stdc++.h>
using namespace std;

int count(int a, int b)
{
    int diff = abs(a-b);
    if (!diff)
        return 0;
    int sum = 0, k = 0;
    while (!(sum >= diff && (sum - diff) % 2 == 0))
    {
        k++;
        sum += k;
    }
    return k;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << count(a, b) << endl;
    }
    return 0;
}