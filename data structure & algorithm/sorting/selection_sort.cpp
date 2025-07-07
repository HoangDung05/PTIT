#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int key = i;
        for(int j = i + 1; j < n; j++)
        {
            if (a[j] < a[key])
            {
                key = j;
            }
        }
        swap(a[i], a[key]);
    }
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
    return 0;
}