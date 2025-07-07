#include <iostream>
using namespace std;
int n;
int a[1000] = {0};

bool check()
{
    for (int i = 0; i < n; i++)
        if (a[i] == 0)
            return 0;
    return 1;
}

void sinh_ke_tiep()
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0)
        {
            a[i] = 1;
            break;
        }
        else
            a[i] = 0;
    }
}

void Genetate()
{
    bool Stop = false;
    while (!Stop)
    {
        for (int i = 0; i < n; i++)
            cout << a[i];
        cout << endl;
        if (check() == 0)
            sinh_ke_tiep();
        else
            Stop = true;
    }
}

int main(int argc, char* argv[])
{
    cin >> n;
    Genetate();
    return 0;
}
