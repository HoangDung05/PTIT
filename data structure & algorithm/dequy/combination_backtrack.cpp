// Duyet tap con k phan tu của 1,2,..n: Quay lui
#include<bits/stdc++.h>
using namespace std;
int n, k, x[100];

void Init()
{
    cin >> n >> k;
    x[0] = 0;
}

void Result()
{
    for (int i = 1; i <= k; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Try(int i) // X=(x1,x2,...,xn)
{
    for (int j = x[i-1]+1; j <= n-k+i; j++)
    {
        x[i] = j;
        if (i == k)
            Result();
        else    
            Try(i+1);
    }
}


int main()
{
    Init();
    Try(1);
    return 0;
}