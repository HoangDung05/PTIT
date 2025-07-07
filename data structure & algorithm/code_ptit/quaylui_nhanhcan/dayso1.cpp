// De qui tuyen tinh
#include<bits/stdc++.h>
using namespace std;
int n;
int a[10];

void Init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void Row()
{
    if (n == 0)
        return;
    else
    {
        cout << "[";
        for (int i = 0; i < n - 1; i++)
            cout << a[i] << " ";
        cout << a[n-1] << "]\n";

        for (int i = 0; i < n - 1; i++)
            a[i] = a[i] + a[i+1];
        n--;
        Row();
    }
}


int main()
{
    int t; cin >> t;
    while (t--)
    {
        Init();
        Row();
    }
    return 0;
}