#include <iostream>
using namespace std;
int n, x[100] = {0}, visited[100] = {0};

void Ghinhan()
{
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Try(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            x[k] = i;
            if (k == n)
                Ghinhan();
            else
                Try(k+1);
            visited[i] = 0;
        }
    }
}

int main(int argc, char* argv[])
{
    cin >> n;
    Try(1);
    return 0;
}
