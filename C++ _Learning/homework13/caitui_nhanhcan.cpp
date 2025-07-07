#include <iostream>
#include <climits>
using namespace std;
int a[1000], c[1000], n, b, FOPT = INT_MIN, x[1000] = {0}, s = 0, dem[1000], best[1000];
float g = 0;

void Ghinhan()
{
    if (g > FOPT)
    {
        FOPT = g;
        for (int i = 1; i <= n; i++)
            best[i] = x[i];
    }
}

void Branch_And_Bound(int k)
{
    for (int y = b/a[k]; y >= 0; y--)
    {
        x[k] = y;
        s += c[k] * x[k];
        b -= a[k] * x[k];
        g = s + b * ((double)c[k+1]/a[k+1]);
        if (k == n)
        {
            g = s;
            Ghinhan();
        }
        else if (g > FOPT)
            Branch_And_Bound(k + 1);
        s -= c[k] * x[k];
        b += a[k] * x[k];
    }
}

int main(int argc, char* argv[])
{
    cout << "So luong do vat trong tui la: ";
    cin >> n;
    cout << "Gia tri su dung: ";
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    cout << "Trong luong: ";
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << "Trong luong toi da cua tui: ";
    cin >> b;
    for (int i = 1; i <= n; i++)
    {
        dem[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double tile1 = (double) c[i]/a[i];
            double tile2 = (double) c[j]/a[j];
            if (tile1 < tile2)
            {
                swap(a[i], a[j]);
                swap(c[i], c[j]);
                swap(dem[i], dem[j]);
            }
        }
    }
    Branch_And_Bound(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "x" << dem[i] << "=" << best[i] << " ";
    }
    cout << endl;
    cout << "Gia tri lon nhat la: " << FOPT;
    return 0;
}

