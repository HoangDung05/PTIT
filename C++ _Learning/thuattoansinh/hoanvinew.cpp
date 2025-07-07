#include <iostream>
using namespace std;
int n, x[1000] = {0}, k;

void khoitao()
{
    for (int i = 1; i <= k; i++)
        x[i] = i;
}

void in()
{
    for (int i = 1; i <= k; i++)
        cout << x[i] << " ";
    cout << endl;
}

int check()
{
    for (int i = 1; i <= k; i++)
        if (x[i] != (n-k+i))
            return 0;
    return 1;
}

void sinh()
{
    int t = k;
    while (x[t] >= (n - k + t)) t--;
    x[t]++;
    for (int i = t + 1; i <= k; i++)
        x[i] = x[t] + (i - t);
}

int main(int argc, char* argv[])
{
    cin >> n >> k;
    khoitao();
    int stop = 0;
    while (!stop)
    {
        in();
        if (check() == 0)
            sinh();
        else
            stop = 1;
    }
}
