#include<bits/stdc++.h>
using namespace std;
int n;
char x[100];
bool OK = true;

void Init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        x[i] = 'A';
}

void Result()
{
    for (int i = 0; i < n; i++)
        cout << x[i];
    cout << " ";
}

void Next_String()
{
    int i = n - 1;
    while (i >= 0 && x[i] == 'B')
    {
        x[i] = 'A';
        i--;
    }
    if (i >= 0)
        x[i] = 'B';
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
            Next_String();
        }
        cout << endl;
        OK = true;
    }
    return 0;
}