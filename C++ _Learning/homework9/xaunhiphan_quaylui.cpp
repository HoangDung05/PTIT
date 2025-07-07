#include <iostream>
using namespace std;
int n;
int a[1000];

void Ghinhan()
{
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << endl;
}

void Try(int i)
{
    for (int y = 0; y <= 1; y++)
    {
        a[i] = y;
        if (i == n)
            Ghinhan();
        else
            Try(i + 1);
    }
}

int main(int argc, char* argv[])
{
    cin >> n;
    Try(1);
    return 0;
}
