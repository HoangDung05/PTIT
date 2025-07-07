#include<bits/stdc++.h>
using namespace std;
int n, k, x[100];

void Init()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> x[i];
}

int Change_NextCombination()
{
    if (x[0] == n-k+1)
        return k;
    int cnt = 0;
    int i = k - 1;
    while (i >= 0 && x[i] == n-k+i+1)
    {
        i--;
    }
    if (i >= 0)
    {
        cnt++;
        x[i]++;
    }
    for (int j = i + 1; j < k; j++)
    {
        x[j] = x[i] + j - i;
        if (x[j] <= n-k+i+1)
            cnt++;
    }
    return cnt;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        Init();
        cout << Change_NextCombination() << endl;
    }
    return 0;
}