
#include<bits/stdc++.h>
using namespace std;
int n, k, x[1001];

void Init()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> x[i];
}

void Result()
{
    for (int i = 0; i < k; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Next_Combination()
{
    int i = k - 1;
    while (i >= 0 && x[i] == n-k+i+1)
    {
        i--;
    }
    if (i >= 0)
    {
        x[i]++;
        for (int j = i + 1; j < k; j++)
            x[j] = x[i] + j - i;
    }
    else
    {
        for (int j = 0; j < k; j++)
        {
            x[j] = j + 1;
        }
    }
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        Init();
        Next_Combination();
        Result();
    }
    return 0;
}