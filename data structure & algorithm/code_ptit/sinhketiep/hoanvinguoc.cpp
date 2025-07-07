#include<bits/stdc++.h>
using namespace std;
int n, x[100];
bool OK = true;

void Init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        x[i] = n - i;
}

void Result()
{
    for (int i = 0; i < n; i++)
        cout << x[i];
    cout << " ";
}

void Next_Reverse_Permutation()
{
    int i = n - 2;
    while (i >= 0 && x[i] < x[i+1])
    {
        i--;
    }
    if (i >= 0)
    {
        int j = n - 1;
        while (j >= 0 && x[j] > x[i])
        {
            j--;
        }
        swap(x[i], x[j]);
        reverse(x+i+1, x+n);
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
            Result();
            Next_Reverse_Permutation();
        }
        cout << endl;
        OK = true;
    }
    return 0;
}