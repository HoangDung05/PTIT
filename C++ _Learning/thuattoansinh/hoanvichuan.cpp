#include <iostream>
using namespace std;
int x[100] = {0}, n;

void taoxau()
{
    for (int i = 1; i <= n; i++)
        x[i] = i;
}

int check()
{
    for (int i = 1; i <= n; i++)
    {
        if (x[i] != (n - i + 1))
            return 0;
    }
    return 1;
}

void in()
{
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void sinh()
{
    int t = n - 1, k = 0;
    while (x[t] > x[t+1]) t--;
    int minn = 10000;
    for (int i = t + 1; i <= n; i++)
    {
        if (x[i] > x[t] && x[i] < minn)
            k = i;
    }
    swap(x[k], x[t]);
    int l = t + 1, r = n;
    while (l <= r)
    {
        swap(x[l], x[r]);
        l++, r--;
    }
}

int main(int argc, char* argv[])
{
    cin >> n;
    taoxau();
    int stop = 0;
    while (!stop)
    {
        in();
        if (check() == 0)
            sinh();
        else
            stop = 1;
    }
    return 0;
}
