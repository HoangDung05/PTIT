#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            bool check = false;
            int min = i;
            for(int j = i + 1; j < n; j++)
                if (a[j] < a[min])
                {
                    check = true;
                    min = j;
                }
            if (!check)
                continue;
            swap(a[i], a[min]);
            ans++;
        }
        cout << ans << endl;
    }
    
    return 0;
}