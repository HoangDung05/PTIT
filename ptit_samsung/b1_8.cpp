#include<bits/stdc++.h>
using namespace std;

int countDivisor(int n)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if (i != (n/i))
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        cout << countDivisor(n) << endl;
    }
    
    
    return 0;
}