#include <iostream>
using namespace std;
int n, k, m;
int x[100];

void ghinhan()
{
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}

int check()
{
    int dem0 = 0, dem1 = 0, check0 = 0, check1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x[i])
        {
            dem1++;
            dem0 = 0;
        }
        else
        {
            dem0++;
            dem1 = 0;
        }
        if (dem0 >= k)
            check0++;
        if (dem1 >= m)
            check1++;
    }
    return check0 == 1 && check1 == 1;
}

void Try (int i)
{
    for (int y = 0; y <= 1; y++)
    {
        x[i] = y;
        if (i == n)
        {
            if (check())
                ghinhan();
        }
        else
            Try(i+1);
    }
}

int main()
{
    cin >> n >> k >> m;
    Try(1);
    return 0;
}
