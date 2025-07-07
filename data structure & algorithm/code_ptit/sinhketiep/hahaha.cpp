#include<iostream>
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
    cout << endl;
}

bool check()
{
    if(x[0] != 'H' || x[n-1] != 'A')
        return false;
    for (int i = 0; i < n-1; i++)
        if (x[i] == 'H' && x[i+1] == 'H')
            return false;
    return true;
}

void Next_Strings()
{
    int i = n - 1;
    while (i >= 0 && x[i] == 'H')
    {
        x[i] = 'A';
        i--;
    }
    if (i >= 0)
        x[i] = 'H';
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
            if (check())
                Result();
            Next_Strings();
        }
        OK = true;
    }
    return 0;
}