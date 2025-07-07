// Duy cac xau nhi phan: Quay lui
#include<bits/stdc++.h>
using namespace std;
int n;
int x[100];

void Init()
{
    cin >> n;
}

void Result()
{
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Try(int i) //X=(x1,x2,...,xn): xi = 0/1
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i==n)
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