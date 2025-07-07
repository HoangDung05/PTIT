#include<bits/stdc++.h>
using namespace std;
int n, x[1001];
bool OK = true;

void Init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
}

void Next_Permutation()
{
    int i = n - 2;
    while (i >= 0 && x[i] > x[i+1])
    {
        i--;
    }
    if (i >= 0)
    {
        int j = n - 1;
        while (x[j] <= x[i] )
        {
            j--;
        }
        swap(x[i], x[j]);
        reverse(x+i+1, x+n);
    }
    else
    {
        for (int j = 0; j < n; j++)
            x[j] = j + 1;
    }
}

void Result()
{
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        Init();
        Next_Permutation();
        Result();
    }
    return 0;
}