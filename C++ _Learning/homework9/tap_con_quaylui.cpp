#include <iostream>

using namespace std;
int x[100];
int n, k;

void Ghinhan()
{
    for (int i = 1; i <=  k; i++)
        cout << x[i];
    cout << endl;
}

void Try(int i)
{
    //Si = {x[i-1] + 1, x[i-1] + 2, ..., n - k + i}
    for (int y = x[i-1] + 1; y <= n - k + i; y++)
    {
        x[i] = y;
        if (i == k)
            Ghinhan();
        else
            Try(i+1);
    }
}

int main(int argc, char* argv[])
{
    cin >> n >> k;
    Try(1);
}
