#include<bits/stdc++.h>
using namespace std;

void Init(int n, int a[], int c[])
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
}

void Dynamic(int n, int v, int a[], int c[])
{
    //1. khai bao bang phuong an: 
    int dp[n+1][v+1];
    //2. khoi tao gia tri ban dau cho bang phuong an: bai toan con co so
    memset(dp, 0, sizeof(dp));
    //3. truy vet bang phuong an, su dung cong thuc truy hoi de tinh gia tri bai toan
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j >= a[i])
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-a[i]] + c[i]);
            }
        }
    }  
    cout << dp[n][v] << endl; 
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, v; cin >> n >> v;
        int a[n+1]={}, c[n+1]={};
        Init(n, a, c);
        Dynamic(n, v, a, c);
    }
    
    
    return 0;
}