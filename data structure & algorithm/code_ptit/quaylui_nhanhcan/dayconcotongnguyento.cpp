#include<bits/stdc++.h>
using namespace std;
int n, a[100], x[100];

void Init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    sort(x+1, x+n+1, greater<int>());
}

void Result()
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
            cout << x[i] << " ";
    }
    cout << endl;
}

bool snt(int k)
{
    if (k < 2)  
        return false;
    for (int i = 2; i <= sqrt(k); i++)
        if (k % i == 0)
            return false;
    return true;
}

bool check()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if(a[i])
            sum += x[i];
    if (snt(sum))
        return true;
    return false;
}

void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n)
        {
            if (check())
                Result();
        }
        else    
            Try(i+1);
    }
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        Init();
        Try(1);
    }
    return 0;
}