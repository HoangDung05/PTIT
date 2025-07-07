#include <iostream>
using namespace std;
int x[1000] = {0}, n;

void in()
{
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

int check()
{
    for (int i = 1; i <= n; i++)
        if (x[i] == 0)
            return 0;
    return 1;
}

void sinh()
{
    int k = n;
    while (x[k] == 1) k--;
    x[k] = 1;
    for (int i = k + 1; i <= n; i++)
        x[i] = 0;
}

int main(int argc, char* argv[])
{
    cin >> n;
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
