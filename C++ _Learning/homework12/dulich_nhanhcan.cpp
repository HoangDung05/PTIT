#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int FOPT = INT_MAX, f = 0, cmin = INT_MAX, n, g = 0;
int c[1000][1000];
bool chuaxet[1000];
int x[1000] = {0};
int dis_best[10000];

void Ghi_nhan()
{
    if (g < FOPT)
    {
        FOPT = g;
        for (int i = 1; i <= n+1; i++)
            dis_best[i] = x[i];
    }
}

void Branch_And_Bound(int k)
{
    for (int j = 2; j <= n; j++)
    {
        if (chuaxet[j])
        {
            x[k] = j;
            chuaxet[j] = false;
            f += c[x[k-1]][x[k]];
            g = f + cmin * (n-k+1);
            if (k == n)
            {
                g = f + c[x[k]][x[1]];
                Ghi_nhan();
            }
            else if (g < FOPT)
                Branch_And_Bound(k+1);
            chuaxet[j] = true;
            f -= c[x[k-1]][x[k]];
        }
    }
}

int main(int argc, char* argv[])
{
    memset(chuaxet, true, sizeof(chuaxet));
    cin >> n;
    x[1] = 1, x[n+1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] < cmin && i != j)
                cmin = c[i][j];
        }
    Branch_And_Bound(2);
    cout << "Chi phi nho nhat la: " << FOPT << endl;
    cout << "Phuong an toi uu: ";
    for(int i = 1; i <= n+1; i++)
        cout << dis_best[i] << " ";
    cout << endl;
    return 0;
}
