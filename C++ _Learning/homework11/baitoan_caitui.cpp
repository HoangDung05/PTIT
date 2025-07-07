#include <bits/stdc++.h>
using namespace std;
int x[100], a[100], c[100], n, b, maxx = 0, tong = 0, best[100];

void nhap(int a[], int n)
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void Ghinhan()
{
    if (tong > maxx)
    {
        maxx = tong;
        for (int i = 1; i <= n; i++)
            best[i] = x[i];
    }
}

void Try(int k)
{
    for (int y = 0; y <= b/a[k]; y++)
    {
        x[k] = y;
        b -= a[k] * x[k];
        tong += c[k] * x[k];
        if (k == n)
            Ghinhan();
        else
            Try(k+1);
        b += a[k] * x[k];
        tong -= c[k] * x[k];
    }
}

int main(int argc, char* argv[])
{
    cout << "So luong do vat la: ";
    cin >> n;
    cout << "Trong luong lan luot la:";
    nhap(a, n);
    cout << "Gia tri su dung lan luot la: ";
    nhap(c, n);
    cout << "Trong luong toi da cua tui la: ";
    cin >> b;
    Try(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "x" << i << "=" << best[i] << " ";
    }
    cout << endl;
    cout << "Gia tri su dung toi da la: " << maxx;

    return 0;
}


