#include<bits/stdc++.h>
using namespace std;
int n, x[100];
bool OK = true;

void Init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    sort(x, x+n);
}

void Result()
{
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
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
        while (x[j] < x[i])
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
    Init();
    while (OK)
    {
        Result();
        Next_Permutation();
    }
    return 0;
}