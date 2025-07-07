#include<bits/stdc++.h>
using namespace std;
int n, x[100], x1[100], stt;
bool OK = true;

void Init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        x[i] = i + 1;
        cin >> x1[i];
    }
    stt = 0;
}

void Next_Permutation()
{
    int i = n - 2;
    while (i >= 0 && x[i] >= x[i+1])
    {
        i--;
    }
    if (i >= 0)
    {
        int j = n - 1;;
        while (x[j] <= x[i])
        {
            j--;
        }
        swap(x[i], x[j]);
        reverse(x+i+1, x+n);
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
            Next_Permutation();
            
            stt++;
        }
        cout << stt << endl;
        OK = true;
    }
    
}