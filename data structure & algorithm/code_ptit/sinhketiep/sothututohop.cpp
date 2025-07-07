#include<bits/stdc++.h>
using namespace std;
int n, k, x[100], x1[100], stt;
bool OK = true;

void Init()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        x[i] = i + 1;
        cin >> x1[i];
    }
    stt = 0;
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

bool check()
{
    for (int i = 0; i < n; i++)
        if (x1[i] != x[i])
            return false;
    return true;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        Init();
        while (OK)
        {
            if (check())
                OK = false;
            Next_Combination();
            stt++;
        }
        cout << stt << endl;
        OK = true;
    }
    return 0;
}