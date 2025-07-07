#include<bits/stdc++.h>
using namespace std;
int n, k, x[100], dem;
bool OK = true, check = true;

void Init()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        x[i] = 0;
    for (int i = n-k; i < n; i++)
        x[i] = 1;
    dem = 1;
}

bool Check()
{
    int dem = 0; 
    for (int i = 0; i < n; i++)
        if (x[i])
            dem++;
    return (dem == k) ? true : false;
}

void Result()
{
    for (int i = 0; i < n; i++)
        cout << x[i];
    cout << endl;
}

void Next_Bits_String()
{
    int i = n - 1; 
    while (i >= 0 && x[i])
    {
        x[i] = 0;
        i--;
    }
    if (i >= 0)
    {
        x[i] = 1;
    }
    else
        OK = false;
}


int main()
{
    int t; cin >> t;
    while (t--)
    {
        Init();
        while (OK)
        {
            if (Check())
                Result();
            Next_Bits_String();
        }
        OK = true;
    }
    return 0;   
}