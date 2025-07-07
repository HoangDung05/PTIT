#include <iostream>
using namespace std;
int n, k;
int a[1000];

bool check()
{
    if (a[1] == n - k + 1)
        return 1;
    return 0;
}

void sinh_ke_tiep()
{
    for (int i = k; i >= 1; i--)
    {
        if (a[i] < n - k + i)
        {
            a[i]++;
            for (int j = i + 1; j <= k; j++)
                a[j] = a[i] + j - i;
            break;
        }
    }
}

void Generate()
{
    for (int i = 1; i <= k; i++)
        a[i] = i;
    bool Stop = false;
    while (!Stop)
    {
        for (int i = 1; i <= k; i++)
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
    cin >> n >> k;
    Generate();
    return 0;
}

