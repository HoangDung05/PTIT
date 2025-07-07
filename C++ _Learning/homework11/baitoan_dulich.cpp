#include <iostream>
#include <cstring>
#include <limits>
using namespace std;
int n, c[100][100], minn = INT_MAX, best[100], chiphi = 0, x[100] = {0}, check[100];

void Ghinhan()
{
    if (chiphi < minn)
    {
        minn = chiphi;
        for (int i = 1; i <= n+1; i++)
            best[i] = x[i];
    }
}

void Try(int k)
{
    for (int y = 2; y <= n; y++)
    {
        if (check[y] == 0)
        {
            check[y] = 1;
            x[k] = y;
            chiphi += c[x[k-1]][x[k]];
            if (k == n)
            {
                chiphi += c[x[k]][x[k+1]];
                Ghinhan();
                chiphi -= c[x[k]][x[k+1]];
            }
            else
                Try(k+1);
            check[y] = 0;
            chiphi -= c[x[k-1]][x[k]];
        }
    }
}

int main(int argc, char* argv[])
{
    cin >> n;
    memset(check, 0, sizeof(check));
    x[1] = 1, x[n+1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    Try(2);
    cout << "Quang duong di la: ";
    for (int i = 1; i <= n+1; i++)
        cout << best[i] << " ";
    cout << endl;
    cout << "Chi phi nho nhat la: " << minn;
}
