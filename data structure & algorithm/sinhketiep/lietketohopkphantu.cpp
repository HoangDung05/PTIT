
#include<bits/stdc++.h>
using namespace std;
int n, k, x[100];
bool OK = true;

void Init()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        x[i] = i + 1;
}

void Result()
{
    for (int i = 0; i < k; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Next_Combination()
{
    int i = k - 1;
    while (i >= 0 && x[i] == n-k+i+1)
    {
        i--;
    }
    if (i >= 0)
    {
        x[i]++;
        for (int j = i + 1; j < k; j++)
            x[j] = x[i] + j - i;
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
        Next_Combination();
    }
    return 0;
}