#include<bits/stdc++.h>
using namespace std;
int n, k, x[100000];

void Init()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> x[i];
}

void Previous_Combination()
{
    int i = k - 1;
    while (i >= 0 && x[i] == x[i-1]+1)
    {
        i--;
    }
    if (i == 0 && x[0]==1) // nếu dãy đang là tập con đầu tiên
        x[0] = n-k+1;
    else
        x[i] = x[i]-1;

    for (int j = k-1; j > i; j--)
        x[j] = n-k+j+1;
}

void Result()
{
    for (int i = 0; i < k; i++)
        cout << x[i] << " ";
    cout << endl;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        Init();
        Previous_Combination();
        Result();
    }
    return 0;
}