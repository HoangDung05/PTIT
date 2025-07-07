#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n; cin >> n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        int dem = 0;
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                dem++;
                n /= i;
            }
        }
        cout << i << " (" << dem << ") ";
    }
    if (n > 0)
    {
        cout << n << " (1) ";
    }
    return 0;
}