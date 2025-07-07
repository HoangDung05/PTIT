// Duyet tap con k phan tu của 1,2,..n: Quay lui
#include<bits/stdc++.h>
using namespace std;
int n, x[100];
bool visited[100];

void Init()
{
    cin >> n;
    fill(visited, visited + 100, true);
}

void Result()
{
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Try(int i) // X=(x1,x2,...,xn)
{
    for (int j = 1; j <= n; j++)
    {
        if (visited[j])
        {
            x[i] = j;
            visited[j] = false;   
        
        if (i == n)
            Result();
        else    
            Try(i+1);
        visited[j] = true;
        }
    }
}

int main()
{
    Init();
    Try(1);
    return 0;
}